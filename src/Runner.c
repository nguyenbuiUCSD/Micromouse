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

int static x_coord = 0;
int static y_coord = 0;
int static curr_dir = NORTH;
int static turn = STRAIGHT;
int maze[16][16];

void Runner_random_turn() {
	 //Start from the middle of cell move half then read value
	int random_num;

	Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
	y_coord++;

	while (1){
		int walls_info = Driver_checkwalls();

		random_num = Micros % 3;

		switch(random_num){
			case 0: // front -> left -> right
				if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
							turn = STRAIGHT;
							Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
							turn = LEFT;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
							turn = RIGHT;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				else {
							turn = UTURN;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				break;

			case 1://left -> front -> right
				if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
						turn = LEFT;
						Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
						Driver_go_straight(0, 0);
						Driver_turn_left(90, 90, RANDOM_TURN_TURNING_SPEED);
											Driver_go_straight(0, 0);
						Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
											Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
							turn = STRAIGHT;
							Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}

				else if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
							turn = RIGHT;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}

				else {
							turn = UTURN;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				break;
			case 2: //right -> front -> left
				if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
					turn = RIGHT;
					Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
					Driver_go_straight(0, 0);
					Driver_turn_right(90, 90, RANDOM_TURN_TURNING_SPEED);
					Driver_go_straight(0, 0);
					Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
					Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
					turn = STRAIGHT;
					Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
								Driver_go_straight(0, 0);
				}

				else if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
							turn = LEFT;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}

				else {
							turn = UTURN;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				break;
		}

		if (turn == RIGHT) {
			curr_dir++;
			curr_dir%=4;
		}

		else if (turn == LEFT) {
			if(curr_dir == NORTH) {
				curr_dir = WEST;
			}
			else {
				curr_dir--;
			}
		}

		else if ( turn == UTURN) {
			curr_dir+=2;
			curr_dir%=4;
		}

		switch(curr_dir) {
		case NORTH:
			y_coord++;
			break;

		case EAST:
			x_coord++;
			break;

		case SOUTH:
			y_coord--;
			break;

		case WEST:
			x_coord--;
			break;
		}

		if(x_coord == 4 && y_coord == 4) {
			Driver_go_straight(0,0);
			return;
		}

	}

}



void Runner_random_turn_two() {
	 //Start from the middle of cell move half then read value
	int random_num;

	Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
	Driver_go_straight(0, 0);

	y_coord++;

	while (1){
		int walls_info = Driver_checkwalls();


		// Update wall info
		//define walls to be SWEN (last 4 positions)
		int n, e, s, w;
		switch(curr_dir){
		case NORTH:
			n = (walls_info >> FRONTWALL_BIT_POSITION) & 1;
			e = (walls_info >> RIGHTWALL_BIT_POSITION)  & 1;
			w = (walls_info >> LEFTWALL_BIT_POSITION) & 1;
			s = 0;
			break;
		case EAST:
			e = (walls_info >> FRONTWALL_BIT_POSITION) & 1;
			s = (walls_info >> RIGHTWALL_BIT_POSITION)  & 1;
			n = (walls_info >> LEFTWALL_BIT_POSITION) & 1;
			w = 0;
			break;
		case SOUTH:
			s = (walls_info >> FRONTWALL_BIT_POSITION) & 1;
			w = (walls_info >> RIGHTWALL_BIT_POSITION)  & 1;
			e = (walls_info >> LEFTWALL_BIT_POSITION) & 1;
			n = 0;
			break;
		case WEST:
			w = (walls_info >> FRONTWALL_BIT_POSITION) & 1;
			n = (walls_info >> RIGHTWALL_BIT_POSITION)  & 1;
			s = (walls_info >> LEFTWALL_BIT_POSITION) & 1;
			e = 0;
			break;
		}
		int curr = 0;
		curr = curr | (n << NORTH);
		curr = curr | (e << EAST);
		curr = curr | (s << SOUTH);
		curr = curr | (w << WEST);
		maze[y_coord][x_coord]&= 0xFFFFFFF0;
		maze[y_coord][x_coord]|= curr;


		// Make the turn

		random_num = Micros % 3;

		switch(random_num){
			case 0: // front -> left -> right
				if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
							turn = STRAIGHT;
							Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
							turn = LEFT;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
							turn = RIGHT;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				else {
							turn = UTURN;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				break;

			case 1://left -> front -> right
				if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
						turn = LEFT;
						Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
						Driver_go_straight(0, 0);
						Driver_turn_left(90, 90, RANDOM_TURN_TURNING_SPEED);
											Driver_go_straight(0, 0);
						Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
											Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
							turn = STRAIGHT;
							Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}

				else if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
							turn = RIGHT;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}

				else {
							turn = UTURN;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				break;
			case 2:// right -> front -> left
				if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
					turn = RIGHT;
					Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
					Driver_go_straight(0, 0);
					Driver_turn_right(90, 90, RANDOM_TURN_TURNING_SPEED);
					Driver_go_straight(0, 0);
					Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
					Driver_go_straight(0, 0);
				}
				else if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
					turn = STRAIGHT;
					Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
								Driver_go_straight(0, 0);
				}

				else if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
							turn = LEFT;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}

				else {
							turn = UTURN;
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Controller_frontwall_corection();
							Driver_go_straight(0, 0);
							Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
							Driver_go_straight(0, 0);
							Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
							Driver_go_straight(0, 0);
				}
				break;
		}

		if (turn == RIGHT) {
			curr_dir++;
			curr_dir%=4;
		}

		else if (turn == LEFT) {
			if(curr_dir == NORTH) {
				curr_dir = WEST;
			}
			else {
				curr_dir--;
			}
		}

		else if ( turn == UTURN) {
			curr_dir+=2;
			curr_dir%=4;
		}

		switch(curr_dir) {
		case NORTH:
			y_coord++;
			break;

		case EAST:
			x_coord++;
			break;

		case SOUTH:
			y_coord--;
			break;

		case WEST:
			x_coord--;
			break;
		}

		if(x_coord == 2 && y_coord == 2) {
			Driver_go_straight(0,0);
			return;
		}



	}
}
