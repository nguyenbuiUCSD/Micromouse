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
 * Runner Define
 */


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

/*
 * Using the new mice
 */
#define L_100MM2COUNT_RATIO 90  // 100 millimeters = 1110 count
#define R_100MM2COUNT_RATIO 90  // 100 millimeters = 1110 count
#define MOUSE_WIDTH 69	// 65mm from left wheels to right wheels



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
#define FRONTWALL_BIT_POSITION 1
#define LEFTWALL_BIT_POSITION 2
#define RIGHTWALL_BIT_POSITION 0
#define CENTER_TO_LEFT_WALL 1425
#define CENTER_TO_RIGHT_WALL 1286
#define CENTER_TO_FRONT_RIGHT 4529
#define CENTER_TO_FRONT_LEFT 4193

#define FRONT_LEFT_THRESHOLD 1200
#define FRONT_RTIGHT_THREHOLD 500
#define DIAGNAL_LEFT_THRESHOLD 250
#define DIAGNAL_RIGHT_THRESHOLD 250

#define SENSOR_RATIO 22
#define MAX_SENSOR_ERR 35
#define FRONT_WALL_CORRECTION_SPEED_LIMIT 20

#endif /* GLOBAL_H_ */
