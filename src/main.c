/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "global.h"
#include "Controller.h"
#include "Driver.h"
#include "delay.h"
#include "led.h"
#include "pwm.h"
#include "encoder.h"
#include "sensor.h"


volatile int32_t leftspeed;
volatile int32_t rightspeed;

volatile int test = 0;

int main(void) {

	// 1. HARDWARE INITIALIZE -------------------------------------------
	Controller_hardware_init();


	// 3. START PROGRAM -------------------------------------------------
	while (1){

LED1_ON;
LED5_ON;
//readSensor();

delay_ms(20);
LED1_OFF;
LED5_OFF;

Driver_go_straight(0, 0);
Driver_go_straight(200, 100);
Driver_go_straight(200, 200);
Driver_go_straight(200, 500);
Driver_go_straight(200, 200);
Driver_go_straight(200, 100);
Driver_go_straight(200, -100);
Driver_go_straight(200, -200);
Driver_go_straight(200, -500);
Driver_go_straight(200, -200);
Driver_go_straight(200, -100);
Driver_go_straight(0, 0);



	}// END MAIN LOOP -----------------------------------------------






}
