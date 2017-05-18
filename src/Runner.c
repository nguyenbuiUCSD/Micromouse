/*
 * Runner.c
 *
 *  Created on: Apr 19, RANDOM_TURN_SPEED17
 *      Author: nguyenbui
 */

#include "stdlib.h"
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
int maze_flood_fill[16][16];

void Runner_maze_init(int x_target, int y_target){
	for (int x = 0; x< 16; x++){
		for (int y = 0; y< 16; y++){
			maze_flood_fill[x][y] = abs(x-x_target) + abs(y-y_target);
			maze[x][y] &= !(1<<VISITED_BIT_POSITION);
		}
	}
}

void Runner_flood_fill(){
	for (int i = 0; i<256; i++)
		for (int x = 0; x< 16; x++)
			for (int y = 0; y< 16; y++){
				if ( maze[x][y]&(1<<VISITED_BIT_POSITION) ){
					int smalest_neighbor = 256;
					if (!(maze[x][y] & (1 << NORTH))) {
						if (smalest_neighbor > maze_flood_fill[x][y+1]){
							smalest_neighbor = maze_flood_fill[x][y+1];
						}
					}

					if (!(maze[x][y] & (1 << EAST))) {
						if (smalest_neighbor > maze_flood_fill[x+1][y]){
								smalest_neighbor = maze_flood_fill[x+1][y];
						}
					}

					if (!(maze[x][y] & (1 << SOUTH))) {
						if (smalest_neighbor > maze_flood_fill[x][y-1]){
							smalest_neighbor = maze_flood_fill[x][y-1];
						}
					}

					if (!(maze[x][y] & (1 << WEST))) {
						if (smalest_neighbor > maze_flood_fill[x-1][y]){
							smalest_neighbor = maze_flood_fill[x-1][y];
						}
					}

					if (smalest_neighbor < 256){
						maze_flood_fill[x][y] = smalest_neighbor + 1;
					}

				}
	}
}



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
//	Driver_go_straight(0, 0);

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


void Runner_explore(int x_target, int y_target) {
	 //Start from the middle of cell move half then read value


	Runner_maze_init (x_target,y_target);


	Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
	Driver_go_straight(0, 0);

	maze[0][0] = 0xFFFFF1E;
	y_coord++;

	while (1){
		int walls_info = Driver_checkwalls();

		int cur_dst, next_direction ;


		// Update wall info
		//define walls to be SWEN (last 4 positions)
		int n, e, s, w, f, l, r;
		switch(curr_dir){
		case NORTH:
			n = f = (walls_info >> FRONTWALL_BIT_POSITION) & 1;
			e = r = (walls_info >> RIGHTWALL_BIT_POSITION)  & 1;
			w = l = (walls_info >> LEFTWALL_BIT_POSITION) & 1;
			s = 0;
			break;
		case EAST:
			e = f = (walls_info >> FRONTWALL_BIT_POSITION) & 1;
			s = r = (walls_info >> RIGHTWALL_BIT_POSITION)  & 1;
			n = l = (walls_info >> LEFTWALL_BIT_POSITION) & 1;
			w = 0;
			break;
		case SOUTH:
			s = f = (walls_info >> FRONTWALL_BIT_POSITION) & 1;
			w = r = (walls_info >> RIGHTWALL_BIT_POSITION)  & 1;
			e = l = (walls_info >> LEFTWALL_BIT_POSITION) & 1;
			n = 0;
			break;
		case WEST:
			w = f = (walls_info >> FRONTWALL_BIT_POSITION) & 1;
			n = r = (walls_info >> RIGHTWALL_BIT_POSITION)  & 1;
			s = l = (walls_info >> LEFTWALL_BIT_POSITION) & 1;
			e = 0;
			break;
		}
		int curr = 0;
		curr = curr | (n << NORTH);
		curr = curr | (e << EAST);
		curr = curr | (s << SOUTH);
		curr = curr | (w << WEST);
		maze[x_coord][y_coord]&= 0xFFFFFFF0;
		maze[x_coord][y_coord]|= curr;

		SET_B(maze[x_coord][y_coord], VISITED_BIT_POSITION);



		/*************************/



		/*
		 * Check distance of open neighbors
		 */
		cur_dst = maze_flood_fill[x_coord][y_coord];

		/*
		 * Flood fill
		 */
		Runner_flood_fill();

		next_direction = UNKNOWN_DIRECTION;
		// Check NORTH neighbor
		if (!n){
			if (maze_flood_fill[x_coord][y_coord+1] == cur_dst - 1){
				next_direction = NORTH;
			}
		}
		// Check EAST neighbor
		if (!e){
			if (maze_flood_fill[x_coord+1][y_coord] == cur_dst - 1){
				next_direction = EAST;
			}
		}
		// Check SOUTH neighbor
		if (!s){
			if (maze_flood_fill[x_coord][y_coord-1] == cur_dst - 1){
				next_direction = SOUTH;
			}
		}
		// Check WEST neighbor
		if (!w){
			if (maze_flood_fill[x_coord-1][y_coord] == cur_dst - 1){
				next_direction = WEST;
			}
		}

		/*
		 * Decide where to turn
		 */
		if (next_direction == UNKNOWN_DIRECTION){
			/*
			 * ERORR_________
			 */
			int error_count = 0;
			while (1){
				Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
				error_count ++;
				if (error_count >10) {
					Driver_go_straight(0, 0);
					return;
				}
			}
		} else {
			if (next_direction == curr_dir)
				turn = STRAIGHT;
			else if (next_direction == curr_dir + 1)
				turn = RIGHT;
			else if (next_direction == (curr_dir - 1)%4)
				turn = LEFT;
			else if (next_direction == (curr_dir + 2)%4)
				turn = UTURN;
		}





		if (turn == RIGHT) {
			/* If there is front wall use front wall to correct error */
			if (f){
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				Controller_frontwall_corection();
//				Driver_go_straight(0, 0);
				Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
//				Driver_go_straight(0, 0);
			/* other wise do curve turn */
			} else {
				Driver_turn_right(90, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
			}

		}

		else if (turn == LEFT) {
			/* If there is front wall use front wall to correct error */
			if (f){
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
				Controller_frontwall_corection();
//				Driver_go_straight(0, 0);
				Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
//				Driver_go_straight(0, 0);
			/* other wise do curve turn */
			} else {
				Driver_turn_left(90, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
			}
		}

		else if ( turn == UTURN) {
			/* GO straight half cell and use front wall to correct err if possible */
			if (f){
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
//				Driver_go_straight(0, 0);
				Controller_frontwall_corection();
//				Driver_go_straight(0, 0);
			} else {
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
//				Driver_go_straight(0, 0);
			}

			/* Make either left or right turn with wall correction */
			if (l){
				Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
				Controller_frontwall_corection();
//				Driver_go_straight(0, 0);
				Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
//				Driver_go_straight(0, 0);
			} else if (r){
				Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
				Controller_frontwall_corection();
//				Driver_go_straight(0, 0);
				Driver_turn_right(0, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
//				Driver_go_straight(0, 0);
			} else {
				Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
				Driver_turn_left(0, 90, RANDOM_TURN_TURNING_SPEED);
//				Driver_go_straight(0, 0);
				Driver_go_straight(HALF_CELL_WIDTH, RANDOM_TURN_SPEED);
//				Driver_go_straight(0, 0);
			}

		} else {
			Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
//			Driver_go_straight(0, 0);
		}



		curr_dir = next_direction;

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

		if(x_coord == x_target && y_coord == y_target) {
			Driver_go_straight(CELL_WIDTH, RANDOM_TURN_SPEED);
			Driver_go_straight(0,0);
			return;
		}



	}
}



