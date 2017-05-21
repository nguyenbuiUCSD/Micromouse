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

volatile int mode = MODE_DEFAULT;


int main(void) {

	// 1. HARDWARE INITIALIZE -------------------------------------------
	Controller_hardware_init();


	// 3. START PROGRAM - choose mode -------------------------------------------------
	mode = MODE_TEST_SENSORS;//MODE_EXPLORE;
	while (1){


	/* ===============================================================	*/
	/*
	 * Test encoder count by going straight-------------------
	 */
	while (mode == MODE_TEST_GO_STRAIGHT){
		/*
		 * BEFORE START ANY FUNCTION REMEMBER TO RESET FUNC_TERMINATED SIGNAL
		 */
		FUNC_TERMINATED = 0;
		/*
		 * Go straight for 3 cell
		 */
		Driver_go_straight(5*CELL_WIDTH, EXPLORE_RUNNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms (10000);
	}
	/* ===============================================================	*/


	/* ===============================================================	*/
	/*
	 * Test sharp turn-------------------
	 */
	while (mode == MODE_TEST_SHARP_TURN){

		/*
		 * BEFORE START ANY FUNCTION REMEMBER TO RESET FUNC_TERMINATED SIGNAL
		 */
		FUNC_TERMINATED = 0;

		/*
		 * Turn right 4 times. then turn left 4 times
		 */
		Driver_turn_right(0,EXPLORE_RIGHT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_right(0,EXPLORE_RIGHT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_right(0,EXPLORE_RIGHT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_right(0,EXPLORE_RIGHT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(2000);

		Driver_turn_left(0,EXPLORE_LEFT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_left(0,EXPLORE_LEFT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_left(0,EXPLORE_LEFT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_left(0,EXPLORE_LEFT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);

		delay_ms (10000);

	}
	/* ===============================================================	*/


	/* ===============================================================	*/
	/*
	 * Test curve turn-------------------
	 */
	while (mode == MODE_TEST_CURVE_TURN){
		/*
		 * BEFORE START ANY FUNCTION REMEMBER TO RESET FUNC_TERMINATED SIGNAL
		 */
		FUNC_TERMINATED = 0;
		/*
		 * Turn right 4 times. then turn left 4 times
		 */
		Driver_turn_right(CURVE_TURN_DIA,EXPLORE_RIGHT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_right(CURVE_TURN_DIA,EXPLORE_RIGHT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_right(CURVE_TURN_DIA,EXPLORE_RIGHT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_right(CURVE_TURN_DIA,EXPLORE_RIGHT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);

		/*
		 * HANDLE THE CASE FUNCTION IS TERMINATED BEFORE FINISH
		 */
		if (FUNC_TERMINATED){
			mode = MODE_DEFAULT;
		}

		delay_ms(2000);

		Driver_turn_left(CURVE_TURN_DIA,EXPLORE_LEFT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_left(CURVE_TURN_DIA,EXPLORE_LEFT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_left(CURVE_TURN_DIA,EXPLORE_LEFT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);
		Driver_turn_left(CURVE_TURN_DIA,EXPLORE_LEFT_TURN_ANGLE,EXPLORE_TURNING_SPEED);
		Driver_go_straight(0,0);
		delay_ms(500);

		/*
		 * HANDLE THE CASE FUNCTION IS TERMINATED BEFORE FINISH
		 */
		if (FUNC_TERMINATED){
			mode = MODE_DEFAULT;
		}

		delay_ms (10000);



	}
	/* ===============================================================	*/


	/* ===============================================================	*/
	/*
	 * RUN EXPLORE-------------------
	 */
	while (mode == MODE_EXPLORE){
		/*
		 * BEFORE START ANY FUNCTION REMEMBER TO RESET FUNC_TERMINATED SIGNAL
		 */
		FUNC_TERMINATED = 0;

		/*
		 * Remember to reset current position if restart from [0,0]
		 */
		x_coord = 0;
		y_coord = 0;
		curr_dir = NORTH;
		turn = STRAIGHT;

		/* Warning before read from flash*/
		for (int cnt = 0; cnt < 10; cnt ++){
			LED1_ON;
			LED6_ON;
			delay_ms(200);
			LED1_OFF;
			LED6_OFF;
			delay_ms(200);
		}
		/* Read maze from flash */
		Controller_readMazeFlash();
		delay_ms (8000);

		/* Explore to the center */
		Runner_explore(2,2);

		/* Warning before save to flash*/
		for (int cnt = 0; cnt < 10; cnt ++){
			ALL_LED_ON;
			delay_ms(200);
			ALL_LED_OFF;
			delay_ms(200);
		}
		/* Save the maze to flash */
		Controller_writeFlash();
		delay_ms (8000);

		Runner_explore(0,0);
		delay_ms (5000);
		Runner_explore(2,2);
		delay_ms (5000);

		/*
		 * HANDLE THE CASE FUNCTION IS TERMINATED BEFORE FINISH
		 */
		if (FUNC_TERMINATED){
			mode = MODE_DEFAULT;
		}

		mode = MODE_DEFAULT;
	}
	/* ===============================================================	*/



	/* ===============================================================	*/
	/*
	 * TEST SENSORS-------------------
	 */
	while (mode == MODE_TEST_SENSORS){
		/*
		 * BEFORE START ANY FUNCTION REMEMBER TO RESET FUNC_TERMINATED SIGNAL
		 */
		FUNC_TERMINATED = 0;

		int testvalue = Controller_checkwall();

		if (testvalue & (1 << FRONTWALL_BIT_POSITION)){
			LED1_ON;
		} else {
			LED1_OFF;
		}

		if (testvalue & (1 << LEFTWALL_BIT_POSITION)){
			LED5_ON;
		} else	{
			LED5_OFF;
		}

		if (testvalue & (1 << RIGHTWALL_BIT_POSITION)) {
			LED2_ON;
		}else{
			LED2_OFF;
		}

		/* Delay 5ms */
		delay_ms(5);

		/*
		 * HANDLE THE CASE FUNCTION IS TERMINATED BEFORE FINISH
		 */
		if (FUNC_TERMINATED){
			mode = MODE_DEFAULT;
		}
	}
	/* ===============================================================	*/


	/* ===============================================================	*/
	/*
	 * TEST SENSORS-------------------
	 */
	while (mode == MODE_TEST_FLASH){
		/*
		 * BEFORE START ANY FUNCTION REMEMBER TO RESET FUNC_TERMINATED SIGNAL
		 */
		FUNC_TERMINATED = 0;

		for (int x = 0; x< 16; x++){
			for (int y = 0; y< 16; y++){
				maze[x][y] = 0x87654321;
			}
		}

		Controller_writeFlash();

		delay_ms(5000);
		/*
		 * HANDLE THE CASE FUNCTION IS TERMINATED BEFORE FINISH
		 */
		if (FUNC_TERMINATED){
			mode = MODE_DEFAULT;
		}
	}
	/* ===============================================================	*/


	/* ===============================================================	*/
	/*
	 * DEFAULT MODE-------------------
	 */
	while (mode == MODE_DEFAULT){
		/*
		 * BEFORE START ANY FUNCTION REMEMBER TO RESET FUNC_TERMINATED SIGNAL
		 */
		FUNC_TERMINATED = 0;

		for (int i = 0; i<5; i++){
			LED1_ON;
			delay_ms(500);
			LED1_OFF;
			delay_ms(500);
		}

		/*
		 * HANDLE THE CASE FUNCTION IS TERMINATED BEFORE FINISH
		 */
		if (FUNC_TERMINATED){
			mode = MODE_DEFAULT;
		}
	}
	/* ===============================================================	*/



	}// END MAIN LOOP -----------------------------------------------

}







/*
 * *******************************************************************
 * *           END - EXAMPLE CODE                             *
 * *******************************************************************
 */



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
		delay_ms(100);
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
