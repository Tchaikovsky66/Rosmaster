/*
 * key1.h
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */

#ifndef KEY_KEY1_H_
#define KEY_KEY1_H_

#include "gpio.h"


#define KEY_PRESS           1
#define KEY_RELEASE         0

#define KEY_MODE_ONE_TIME   1
#define KEY_MODE_ALWAYS     0


uint8_t Key1_State(uint8_t mode);


#endif /* KEY_KEY1_H_ */
