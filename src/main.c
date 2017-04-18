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
#include "delay.h"
#include "led.h"
#include "pwm.h"
#include "encoder.h"


volatile int32_t leftspeed;
volatile int32_t rightspeed;


int main(void) {

	// 1. HARDWARE INITIALIZE -------------------------------------------
	Controller_hardware_init();


	// 3. START PROGRAM -------------------------------------------------
	while (1){

LED1_ON;
LED5_ON;
delay_ms(10);

leftspeed = getLeftEncCountAndReset();
rightspeed = getRightEncCountAndReset();

printf("left speed %d", leftspeed);
printf("right speed %d", rightspeed);

/*
LED1_OFF;
LED5_OFF;
delay_ms(500);
LED1_ON;
LED5_ON;
delay_ms(500);
LED1_OFF;
LED5_OFF;
delay_ms(500);
LED1_ON;
LED5_ON;
delay_ms(500);
LED1_OFF;
LED5_OFF;
delay_ms(500);
LED1_ON;
LED5_ON;
delay_ms(500);
LED1_OFF;
LED5_OFF;
delay_ms(500);
LED1_ON;
LED5_ON;
delay_ms(500);
LED1_OFF;
LED5_OFF;
delay_ms(100);


LED2_ON;
LED6_ON;
delay_ms(550);
LED2_OFF;
LED6_OFF;
delay_ms(550);
LED2_ON;
LED6_ON;
delay_ms(550);
LED2_OFF;
LED6_OFF;
delay_ms(550);
LED2_ON;
LED6_ON;
delay_ms(550);
LED2_OFF;
LED6_OFF;
delay_ms(550);
LED2_ON;
LED6_ON;
delay_ms(550);
LED2_OFF;
LED6_OFF;
delay_ms(550);
LED2_ON;
LED6_ON;
delay_ms(550);
LED2_OFF;
LED6_OFF;
delay_ms(100);


LED3_ON;
LED4_ON;
delay_ms(55);
LED3_OFF;
LED4_OFF;
delay_ms(55);
LED3_ON;
LED4_ON;
delay_ms(55);
LED3_OFF;
LED4_OFF;
delay_ms(55);
LED3_ON;
LED4_ON;
delay_ms(55);
LED3_OFF;
LED4_OFF;
delay_ms(55);
LED3_ON;
LED4_ON;
delay_ms(55);
LED3_OFF;
LED4_OFF;
delay_ms(55);
LED3_ON;
LED4_ON;
delay_ms(55);
LED3_OFF;
LED4_OFF;
delay_ms(100);

setLeftPwm(500);
setRightPwm(500);
delay_ms(3000);

setLeftPwm(0);
setRightPwm(0);
delay_ms(30);

*/

	}// END MAIN LOOP -----------------------------------------------






}
