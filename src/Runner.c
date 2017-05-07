/*
 * Runner.c
 *
 *  Created on: Apr 19, RANDOM_TURN_SPEED17
 *      Author: nguyenbui
 */


#include "delay.h"
#include "Driver.h"
#include "global.h"

#define RANDOM_TURN_SPEED 35
#define RANDOM_TURN_TURNING_SPEED 35

void Runner_random_turn() {
	// Start from the middle of cell move half then read value
	int random_num;

	Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);

	while (1){
		int walls_info = Driver_checkwalls();

		random_num = Micros % 3;

		switch(random_num){
			case 0: // front -> left -> right
				if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
							Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}
				else {
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}
				break;

			case 1://left -> front -> right
				if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
			//			Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
			//			Driver_go_straight(0, 0);
						Driver_turn_left(90, 90, RANDOM_TURN_TURNING_SPEED);
								//			Driver_go_straight(0, 0);
			//			Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
								//			Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
							Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}

				else if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}

				else {
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}
				break;
			case 2: //right -> front -> left
				if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
		//			Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
		//			Driver_go_straight(0, 0);
					Driver_turn_right(90, 90, RANDOM_TURN_TURNING_SPEED);
		//			Driver_go_straight(0, 0);
		//			Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
		//			Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
					Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
					//			Driver_go_straight(0, 0);
				}

				else if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}

				else {
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Controller_frontwall_corection();
				//			Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
				//			Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				//			Driver_go_straight(0, 0);
				}
				break;
		}
	}

}
