/*
 * Controller.c
 *
 *  Created on: Apr 17, 2017
 *      Author: nguyenbui
 */
#include <stdio.h>
#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "pwm.h"
#include "encoder.h"
#include "stdlib.h"
#include "adc.h"
#include "pid.h"
#include "sensor.h"
#include "global.h"
/*
 * This function is used to initialize all hardware needed.
 */
void Controller_hardware_init(void) {

	Systick_Configuration();

	LED_Configuration();
	ALL_LED_OFF;

	PWM_Configuration();
	setLeftPwm(0);
	setRightPwm(0);

	Encoder_Configration();

	ADC_Config();

	delay_ms(5000);
}

/*
 * This fution is used to set the speed of both motor
 */
void Controller_run(int left_distance, int right_distance, int left_speed, int right_speed){

	// Declaration of all variables
	volatile int left_EN; // left encoder count
	volatile int right_EN; // right encoder count
	volatile int pid_err, temp=0;
	volatile int lpwm, rpwm;

	volatile int wall_err = 0;


	// Reset PID
	pid_reset();


	// Break --
	// WHen ever speed set to 0. break for 200ms
	if ((left_speed == 0) && (right_speed ==0)){
		int curr_time = Millis;
		while ( (Millis - curr_time) < 200){
			pid_err = - global_left_speed;
			lpwm = pid_left_motor(pid_err);
			pid_err = - global_right_speed;
			rpwm = pid_right_motor(pid_err);
			setLeftPwm(lpwm);
			setRightPwm(rpwm);
		}

		setLeftPwm(0);
		setRightPwm(0);

		return;
	}

	// Save the value in the Encoder counter reg
	left_EN = getLeftDistance();
	right_EN = getRightDistance();



	// This line of code can cause trouble if the encoder rigister is overflow
	// Loop until mice finish the given distance
	// Distance is allway positive, this was calculated from caller (Driver)
	while ( (abs(getLeftDistance() - left_EN) < (left_distance))||
					(abs(getRightDistance() - right_EN) < (right_distance))){


		// Correct position base on wall sensor infomation
		// Only corret when going straight
		if (left_speed == right_speed){
			// read infomation
			read_side_sensors();


			// CASE 2: have left wall
			if (LDSensor > (CENTER_TO_LEFT_WALL+300)){
				if (temp > 300){
					wall_err = (LDSensor - CENTER_TO_LEFT_WALL)/SENSOR_RATIO;
					// Check if error is valid for correction ( too far from wall)
					if (wall_err > (MAX_SENSOR_ERR)) wall_err = MAX_SENSOR_ERR;
					if (wall_err < -(MAX_SENSOR_ERR)) wall_err = -(MAX_SENSOR_ERR);
				} else {
					temp ++;
				}
			}

			// Case 3: Use right wall for correction
			else if (RDSensor > (CENTER_TO_RIGHT_WALL+300)){
				if (temp >300){
					wall_err = -(RDSensor - CENTER_TO_RIGHT_WALL)/SENSOR_RATIO;
					if (wall_err > (MAX_SENSOR_ERR)) wall_err = MAX_SENSOR_ERR;
					if (wall_err < -(MAX_SENSOR_ERR)) wall_err = -(MAX_SENSOR_ERR);
				} else {
					temp ++;
				}

			} else {
				temp = 0;
				wall_err = 0;
			}
		}
		else {
			wall_err = 0;
		}


		// Left motor error to PID
		pid_err = left_speed - global_left_speed + wall_err;
		lpwm = sensor_pid_left_motor(pid_err);

		// Right motor error to PID
		pid_err = right_speed - global_right_speed - wall_err;
		rpwm = sensor_pid_right_motor(pid_err);

		// Set pwm
		setLeftPwm(lpwm);
		setRightPwm(rpwm);
	}

}


void Controller_frontwall_corection(){

	int current_time = Millis;
	int front_left, front_right;

	// Reset PID
	pid_reset();
	while((Millis - current_time) < 500){
		readFrontSensor();
		front_left = (CENTER_TO_FRONT_LEFT - FLSensor)/FRONT_WALL_SENSOR_RATIO;
		front_right = (CENTER_TO_FRONT_RIGHT - FRSensor)/FRONT_WALL_SENSOR_RATIO;

		if (front_left > FRONT_WALL_CORRECTION_SPEED_LIMIT)
			front_left = FRONT_WALL_CORRECTION_SPEED_LIMIT;
		if (front_left < -FRONT_WALL_CORRECTION_SPEED_LIMIT)
			front_left = -FRONT_WALL_CORRECTION_SPEED_LIMIT;
		if (front_right > FRONT_WALL_CORRECTION_SPEED_LIMIT)
			front_right = FRONT_WALL_CORRECTION_SPEED_LIMIT;
		if (front_right < -FRONT_WALL_CORRECTION_SPEED_LIMIT)
			front_right = -FRONT_WALL_CORRECTION_SPEED_LIMIT;

		// Left motor error to PID
		front_left = sensor_pid_left_motor(front_left - global_left_speed);
		// Right motor error to PID
		front_right = sensor_pid_right_motor(front_right - global_right_speed);

		// Set pwm
		setLeftPwm(front_left);
		setRightPwm(front_right);

	}
	// Stay still
	Controller_run(0,0,0,0);
}

int Controller_checkwall(void)
{
	int returnvalue = 0;

	readSensor();
	if (FLSensor > FRONT_LEFT_THRESHOLD && FRSensor > FRONT_RIGHT_THRESHOLD)
		returnvalue |= (1 << FRONTWALL_BIT_POSITION );
	if (LDSensor > DIAGNAL_LEFT_THRESHOLD)
		returnvalue |= (1 << LEFTWALL_BIT_POSITION);
	if (RDSensor > DIAGNAL_RIGHT_THRESHOLD)
		returnvalue |= (1 << RIGHTWALL_BIT_POSITION);

	return returnvalue;

}
