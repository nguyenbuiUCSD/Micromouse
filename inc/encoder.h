/*
 * encoder.h
 *
 *  Created on: Apr 17, 2017
 *      Author: nguyenbui
 */

#ifndef ENCODER_H_
#define ENCODER_H_

int32_t getLeftEncCount(void);
int32_t getRightEncCount(void);

int32_t getLeftEncCountAndReset(void);
int32_t getRightEncCountAndReset(void);

int32_t getLeftDistance(void);
int32_t getRightDistance(void);

void setRightEncCount(int32_t speed);
void setLeftEncCount(int32_t speed);
void Encoder_Configration(void);


#endif /* ENCODER_H_ */
