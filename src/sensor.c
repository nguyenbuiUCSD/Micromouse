/*
 * sensor.c
 *
 *  Created on: Apr 17, 2017
 *      Author: jocelyntran
 */
#include "stm32f4xx.h"
#include <stdio.h>
#include "global.h"
#include "adc.h"
#include "delay.h"
#include "led.h"

volatile int32_t volMeter = 0;
volatile int32_t voltage = 0;
volatile int32_t FLSensor = 0;
volatile int32_t FRSensor = 0;
volatile int32_t LDSensor = 0;
volatile int32_t RDSensor = 0;

/*read IR sensors*/
void readSensor(void)
{
	u32 curt;
//read DC value

	FLSensor = read_FL_Sensor;
	FRSensor = read_FR_Sensor;
	LDSensor = read_LD_Sensor;
	RDSensor = read_RD_Sensor;

	curt = micros();

//left front sensor
	FH_EM_ON;
	elapseMicros(50,curt);
	FLSensor = read_FL_Sensor - FLSensor;
	FH_EM_OFF;
	if(FLSensor < 0)//error check
		FLSensor = 0;
 	elapseMicros(150,curt);
//right front sensor
	FH_EM_ON;
	elapseMicros(200,curt);
	FRSensor = read_FR_Sensor - FRSensor;
	FH_EM_OFF;
	if(FRSensor < 0)
		FRSensor = 0;
 	elapseMicros(300,curt);
// left diagonal sensors
	LD_EM_ON;
	elapseMicros(350,curt);
	LDSensor = read_LD_Sensor - LDSensor;
	LD_EM_OFF;
	if(LDSensor < 0)
		LDSensor = 0;
	elapseMicros(400,curt);
// right diagonal sensors
	RD_EM_ON;
	elapseMicros(450,curt);
	RDSensor = read_RD_Sensor - RDSensor;
	RD_EM_OFF;
	if(RDSensor < 0)
		RDSensor = 0;
	elapseMicros(500,curt);

	FLSensor /= 10;
	FRSensor /= 10;
	LDSensor /= 10;
	RDSensor /= 10;
}



/*read voltage meter*/
void readVolMeter(void)
{          //3240 = 7.85V
	volMeter = read_Vol_Meter;//raw value
	voltage = volMeter*809/3248;//actual voltage value  ex) 8.2V = 8200
}


void lowBatCheck(void)
{
}


