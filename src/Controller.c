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
}

/*
 * This fution is used to set the speed of both motor
 */
void Controller_run(int left_distance, int right_distance, int left_speed, int right_speed){

	// Declaration of all variables
	int left_EN; // left encoder count
	int right_EN; // right encoder count


	if ((left_distance == 0)&&(right_distance == 0)) {
		setLeftPwm(left_speed);
		setRightPwm(right_speed);
		return;
	}

	// Save the value in the Encoder counter reg
	left_EN = getLeftDistance();
	right_EN = getRightDistance();


	// Set speed of left and right motor
	// Then keep track on the distance
	// Return when finish the distance.
	setLeftPwm(left_speed);
	setRightPwm(right_speed+6);

	// This line of code can cause trouble if the encoder rigister is overflow
	// Loop until mice finish the given distance
	// Distance is allway positive, this was calculated from caller (Driver)
	while ( (abs(getLeftDistance() - left_EN) < (left_distance))||
					(abs(getRightDistance() - right_EN) < (right_distance))){

	}

}

