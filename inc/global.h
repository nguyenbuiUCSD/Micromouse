/*
 * global.h
 *
 *  Created on: Apr 17, 2017
 *      Author: nguyenbui
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

// Type define here
// Check development guide for complete info
typedef int Speed;
typedef int Distance;
typedef int Radius;
typedef int Angle;
typedef int Walls;
typedef int Cell_info;
typedef int Cell_label;


/*
 * Bit manipulation macro
 */
#define CLR_B(p,n) ((p) &= ~((1) << (n)))
#define SET_B(p,n) ((p) |= ((1) << (n)))
#define READ_B(p,n) ((p) & ((1) << (n)))

/*
 * Runner Define
 */
#define ROW_DEST 7
#define COLUMN_DEST 7


/*
 * Driver Define
 */
#define M_PI 31416 //x10^(-4)
#define E_6	1000000 // 10^6
#define E_5	100000 // 10^5
#define E_4	10000 // 10^4
#define E_3	1000 // 10^3
#define E_2	100 // 10^2
#define CELL_WIDTH 180
#define HALF_CELL_WIDTH 80

/*
 * Using the new mice
 */
#define L_100MM2COUNT_RATIO 88  //old 88 - 100 millimeters = 1110 count
#define R_100MM2COUNT_RATIO 88  //old 88 - 100 millimeters = 1110 count
#define MOUSE_WIDTH 69	// 69mm from left wheels to right wheels



/*
 * These setting are for the basic mouse board
 * #define L_100MM2COUNT_RATIO 1150  // 100 millimeters = 1110 count
 * #define R_100MM2COUNT_RATIO 1150  // 100 millimeters = 1110 count
 * #define MOUSE_WIDTH 83	// 65mm from left wheels to right wheels
 */
/*
 * Controller Define
 */
/*
 * WALL INFO
 * This depend on type of wall
 */
#define VISITED_BIT_POSITION 4
#define FRONTWALL_BIT_POSITION 0
#define LEFTWALL_BIT_POSITION 3
#define RIGHTWALL_BIT_POSITION 1
#define CENTER_TO_LEFT_WALL 1268
#define CENTER_TO_RIGHT_WALL 1283
#define CENTER_TO_FRONT_RIGHT 4219
#define CENTER_TO_FRONT_LEFT 3112

#define FRONT_LEFT_THRESHOLD 300
#define FRONT_RIGHT_THRESHOLD 300
#define DIAGNAL_LEFT_THRESHOLD 200
#define DIAGNAL_RIGHT_THRESHOLD 200

#define SENSOR_RATIO 25
#define MAX_SENSOR_ERR 5
#define FRONT_WALL_CORRECTION_SPEED_LIMIT 10
#define FRONT_WALL_SENSOR_RATIO 5

/*
 * DIRECTIONS
 * This depends on which way the mouse is facing
 */
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define UNKNOWN_DIRECTION 5

/*
 * TURNS
 * This depends on which way the mouse is turning
 */
#define STRAIGHT 0
#define RIGHT 1
#define UTURN 2
#define LEFT 3

#endif /* GLOBAL_H_ */
