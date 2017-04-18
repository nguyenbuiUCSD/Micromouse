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


void Controller_hardware_init(void) {

	Systick_Configuration();

	LED_Configuration();
	ALL_LED_OFF;

	PWM_Configuration();
	setLeftPwm(0);
	setRightPwm(0);

	Encoder_Configration();
}
