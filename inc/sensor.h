/*
 * sensor.h
 *
 *  Created on: Apr 17, 2017
 *      Author: jocelyntran
 */

#ifndef SENSOR_H_
#define SENSOR_H_

extern int reflectionRate;

extern int32_t volMeter;
extern int32_t voltage;

/* Sensors: front left, front right, left diagonal, right diagonal */
extern int32_t FLSensor;
extern int32_t FRSensor;
extern int32_t LDSensor;
extern int32_t RDSensor;

extern int32_t Outz;
extern int32_t aSpeed;
extern int32_t angle;

void readSensor(void);
void readGyro(void);
void readVolMeter(void);
void lowBatCheck(void);

#endif /* SENSOR_H_ */
