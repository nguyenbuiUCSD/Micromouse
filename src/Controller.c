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
}

/*
 * This fution is used to set the speed of both motor
 */
void Controller_run(int left_distance, int right_distance, int left_speed, int right_speed){

	// Declaration of all variables
	volatile int left_EN; // left encoder count
	volatile int right_EN; // right encoder count
	volatile int pid_err;
	volatile int lpwm, rpwm;

	if ((left_distance == 0)&&(right_distance == 0)) {
		setLeftPwm(left_speed);
		setRightPwm(right_speed);
		return;
	}

	// Save the value in the Encoder counter reg
	left_EN = getLeftDistance();
	right_EN = getRightDistance();

	// Reset PID
	pid_reset();

	// This line of code can cause trouble if the encoder rigister is overflow
	// Loop until mice finish the given distance
	// Distance is allway positive, this was calculated from caller (Driver)
	while ( (abs(getLeftDistance() - left_EN) < (left_distance))||
					(abs(getRightDistance() - right_EN) < (right_distance))){
		pid_err = left_speed - global_left_speed;
		lpwm = pid_left_motor(pid_err);
		pid_err = right_speed - global_right_speed;
		rpwm = pid_right_motor(pid_err);
		setLeftPwm(lpwm);
		setRightPwm(rpwm);
		delay_ms (1);
	}

}

