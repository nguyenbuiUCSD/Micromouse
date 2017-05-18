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
#include "Runner.h"
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

/*
 * Test Random turn search -------------------
 */
		Runner_explore(2,2);
		delay_ms(10000);

/*
 * Calibrate wall sensor ---------------------
 */
//		LED1_ON;
//		LED5_ON;
//		int testvalue = Controller_checkwall();
//		delay_ms(500);
//		LED1_OFF;
//		LED5_OFF;

/*
		int testvalue = Controller_checkwall();

		if (testvalue & (1 << FRONTWALL_BIT_POSITION))
		{
		LED1_ON;
		}

		else
		{
		LED1_OFF;
		delay_ms(1000);
		}

		if (testvalue & (1 << LEFTWALL_BIT_POSITION))
				{
				LED5_ON;
				}

				else
				{
				LED5_OFF;
				}

		if (testvalue & (1 << RIGHTWALL_BIT_POSITION))
				{
				LED2_ON;

				}

				else
				{
				LED2_OFF;
				}

*/


/*
		LED1_ON;
		LED5_ON;
		delay_ms(3000);
		Driver_turn_right(0,90,15);
		Driver_go_straight(0, 0);
		delay_ms(3000);
		Driver_turn_right(0,90,15);
		Driver_go_straight(0, 0);
		delay_ms(3000);
		Driver_turn_right(0,90,15);
		Driver_go_straight(0, 0);
		delay_ms(3000);
		Driver_turn_right(0,90,15);
		Driver_go_straight(0, 0);
		delay_ms(3000);

		Driver_turn_left(0,90,15);
		Driver_go_straight(0, 0);
		delay_ms(3000);
		Driver_turn_left(0,90,15);
		Driver_go_straight(0, 0);
		delay_ms(3000);
		Driver_turn_left(0,90,15);
		Driver_go_straight(0, 0);
		delay_ms(3000);
		Driver_turn_left(0,90,15);
		Driver_go_straight(0, 0);

*/

	/*	Driver_go_straight(CELL_WIDTH, 30);

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

		delay_ms(3000);

		LED1_OFF;
		LED5_OFF;
*/

	}// END MAIN LOOP -----------------------------------------------

}
