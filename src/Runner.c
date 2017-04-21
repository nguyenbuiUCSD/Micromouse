/*
 * Runner.c
 *
 *  Created on: Apr 19, 2017
 *      Author: nguyenbui
 */


#include "Driver.h"
#include "global.h"

void random_turn() {
	int Walls = Driver_checkwalls();
	//go through and convert to integer, true is wall
	int NorthWall = 0;
	int EastWall = 0;
	int WestWall = 0;
	if (Walls % 2 == 1) {
		EastWall = 1;
		Walls /= 2;
	}
	if (Walls % 2 == 1) {
		NorthWall = 1;
		Walls /= 2;
	}
	if (Walls % 2 == 1) {
		WestWall = 1;
		Walls /= 2;
	}

	if (!NorthWall) {
		Driver_go_straight(CELL_WIDTH, 20);
	}
	else if (!WestWall) {
		Driver_turn_left(0, 90, 20);
		Driver_go_straight(CELL_WIDTH, 20);
	}
	else if (!EastWall) {
		Driver_turn_right(0, 90, 20);
		Driver_go_straight(CELL_WIDTH, 20);
	}
	else {
		Driver_turn_left(0, 180, 20);
		Driver_go_straight(CELL_WIDTH, 20);
	}

}
