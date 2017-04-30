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

		Driver_go_straight(CELL_WIDTH, 30);

		Controller_frontwall_corection();

		Driver_turn_right(0,90,15);

		Controller_frontwall_corection();

		Driver_turn_right(0,90,15);

		Driver_go_straight(0, 0);

		Driver_go_straight(CELL_WIDTH, 30);

		Controller_frontwall_corection();

		Driver_turn_left(0,90,15);

		Controller_frontwall_corection();

		Driver_turn_left(0,90,15);

		Driver_go_straight(0, 0);

		delay_ms(2000);

		LED1_OFF;
		LED5_OFF;


	}// END MAIN LOOP -----------------------------------------------

}
