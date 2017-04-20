/*
 * sensor.c
 *
 *  Created on: Apr 17, 2017
 *      Author: jocelyntran
 */
#include "stm32f4xx.h"

//#include "global.h"
#include "sensor.h"
#include "adc.h"
#include "delay.h"
#include "pwm.h"
#include "led.h"
#include <stdio.h>
#include "encoder.h"

int reflectionRate = 1000;//which is 1.000 (converted to ingeter)

int32_t volMeter = 0;
int32_t voltage = 0;
int32_t FLSensor = 0;
int32_t FRSensor = 0;
int32_t LDSensor = 0;
int32_t RDSensor = 0;
int32_t Outz = 0;
int32_t aSpeed = 0;//angular velocity
int32_t angle = 0;


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
	elapseMicros(550,curt);

	FLSensor = FLSensor*reflectionRate/1000;
	FRSensor = FRSensor*reflectionRate/1000;
	LDSensor = LDSensor*reflectionRate/1000;
	RDSensor = RDSensor*reflectionRate/1000;
}


/*read gyro*/
void readGyro(void)
{	                      //k=19791(sum for sample in 1 second)    101376287 for 50 seconds with 5000 samples
	int i;
	int sampleNum = 20;
	aSpeed = 0;
	for(i=0;i<sampleNum;i++)
	aSpeed += read_Outz;
	aSpeed *= 50000/sampleNum;
	aSpeed -= 92980000;
	aSpeed /= 50000;
	aSpeed /= 4;
	angle += aSpeed;
}


/*read voltage meter*/
void readVolMeter(void)
{          //3240 = 7.85V
	volMeter = read_Vol_Meter;//raw value
	voltage = volMeter*809/3248;//actual voltage value  ex) 8.2V = 8200
}


void lowBatCheck(void)
{
  if(voltage < 700) //alert when battery Voltage lower than 7V
	{

		setLeftPwm(0);
		setRightPwm(0);

		while(1)
		{
			// displayMatrix("Lbat");
			//beep_on;
			ALL_LED_OFF;
			delay_ms(200);

			// clearScreen();
			//beep_off;
			ALL_LED_ON;
			delay_ms(200);
		}
	}
  else {
		  // displayInt(voltage);
		  delay_ms(1000);
	}
}


