/*
 * beep.cpp
 *
 *  Created on: May 10, 2023
 *      Author: Shiwe
 */

#include "beep.hpp"


beep::beep() {
	// TODO Auto-generated constructor stub

}

beep::~beep() {
	// TODO Auto-generated destructor stub
}

beep::beep(uint16_t t){
	if(t == 0){

				BEEP_OFF();

			}
		if(t == 1){

				BEEP_ON();

			}
			if(t > 10){
				Beep_set_state(beep_state_delay);
				Beep_set_time(t / 10);
				BEEP_ON();
			}
}
/* 设置延时时间 */
void beep::Beep_on_time(uint16_t time){

		if(time == 0){
			Beep_set_state(beep_state_off);
			Beep_set_time(0);
			BEEP_OFF();

		}
		if(time == 1){
			Beep_set_state(beep_state_on);
			Beep_set_time(0);
			BEEP_ON();

		}
		if(time > 10){
			Beep_set_state(beep_state_delay);
			Beep_set_time(time / 10);
			BEEP_ON();

		}
}

/* 超时自动关闭。每10ms一次 */
void beep::Beep_timeout_close_handle(){
	if(Beep_get_state() == beep_state_delay)
	{
		if(beep_on_time == 0)
		{
			Beep_set_state(beep_state_off);
			BEEP_OFF();
		}
		else
		{
			beep_on_time--;
		}
	}
//	if (beep_state - 1 == (HAL_GetTick()%beep_on_time == 0)){
//					Beep_set_state(beep_state_off);
//					BEEP_OFF();
//	}
}

