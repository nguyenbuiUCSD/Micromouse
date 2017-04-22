/*
 * pid.c
 *
 *  Created on: Apr 19, 2017
 *      Author: nguyenbui
 */

/*
 * All the constant scale to 1000
 */
#define LKP 1100
#define LKI 17
#define LKD 28
#define RKP 1100
#define RKI 17
#define RKD 28

volatile int left_old_err, left_intergral;
volatile int right_old_err, right_intergral;

int pid_left_motor(int err){
	int derivative = (err - left_old_err);
	left_intergral = left_intergral + err ;
	int lpwm = (LKP*err + LKI*left_intergral + LKD*derivative);
	left_old_err = err; // Store the old error
	return lpwm = lpwm/1000; // Scale down cz we need very small change of KI
}


int pid_right_motor(int err){
	int derivative = (err - right_old_err);
	right_intergral = right_intergral + err ;
	int rpwm = (RKP*err + RKI*right_intergral + RKD*derivative);
	right_old_err = err; // Store the old error
	return rpwm = rpwm/1000; // Scale down cz we need very small change of KI
}


void pid_reset(void){
	left_old_err = 0;
	left_intergral = 0;

	right_old_err = 0;
	right_intergral = 0;
}
