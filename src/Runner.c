/*
 * Runner.c
 *
 *  Created on: Apr 19, 2017
 *      Author: nguyenbui
 */


#include "Driver.h"
#include "global.h"

void Runner_random_turn() {
	while (1){
		int walls_info = Driver_checkwalls();

		if (!(walls_info & (1 << FRONTWALL_BIT_POSITION))) {
			Driver_go_straight(CELL_WIDTH, 20);
		}
		else if (!(walls_info & (1 << LEFTWALL_BIT_POSITION))) {
			Driver_turn_left(0, 90, 15);
			Driver_go_straight(CELL_WIDTH, 20);
		}
		else if (!(walls_info & (1 << RIGHTWALL_BIT_POSITION))) {
			Driver_turn_right(0, 90, 15);
			Driver_go_straight(CELL_WIDTH, 20);
		}
		else {
			Controller_frontwall_corection();
			Driver_turn_left(0, 90, 15);
			Controller_frontwall_corection();
			Driver_turn_left(0, 90, 15);
			Driver_go_straight(CELL_WIDTH, 20);
		}
	}

}
