/*
 * beep.hpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */

#ifndef SRC_BEEP_HPP_
#define SRC_BEEP_HPP_

#define beep_state_off		0
#define beep_state_on		1
#define beep_state_delay	2

#define BEEP_ON()        HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET)
#define BEEP_OFF()       HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET)

#include "main.h"

static uint8_t beep_state;			//蜂鸣器状态
static uint16_t beep_on_time;		//蜂鸣器打开时间

class beep {
private:
//	uint8_t beep_state;			//蜂鸣器状态
//	uint16_t beep_on_time;		//蜂鸣器打开时间
public:




	beep();
	beep(uint16_t time);
	virtual ~beep();

	uint8_t Beep_get_state(){
		return beep_state;
	}
	void Beep_set_state(uint8_t state){
		beep_state = state;
	}
	uint16_t Beep_get_time(){
		return beep_on_time;
	}
	void Beep_set_time(uint16_t time){
		beep_on_time = time;
	}

	/* 设置延时时间 */
	void Beep_on_time(uint16_t time);

	/* 超时自动关闭 */
	void Beep_timeout_close_handle();
};


#endif /* SRC_BEEP_HPP_ */
