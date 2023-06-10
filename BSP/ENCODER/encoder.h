/*
 * encoder.h
 *
 *  Created on: May 25, 2023
 *      Author: Shiwe
 */

#ifndef ENCODER_ENCODER_H_
#define ENCODER_ENCODER_H_

#include "stdint.h"


// 轮子转一整圈，编码器获得的脉冲数:30*11*2*2
// One full turn of the wheel, the number of pulses picked up by the coder: 30*11*2*2
#define ENCODER_CIRCLE           (1320)

void Encoder_Init(void);
void Encoder_Update_Count(void);
int Encoder_Get_Count_Now(uint8_t Motor_id);
void Encoder_Get_ALL(int* Encoder_all);
void Encoder_Turn(int circle);



#endif /* ENCODER_ENCODER_H_ */
