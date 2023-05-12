/*
 * key1.h
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */

#ifndef KEY_KEY1_H_
#define KEY_KEY1_H_

#define KEY_PRESSED 	1
#define KEY_RELEASED	0
#define TOOGLE_MODE		3
#define GET_STATE		4
#include "main.h"


class key1 {
private:
	uint8_t state;
public:
	key1();
	key1(uint8_t );
	virtual ~key1();
	bool Key_get_state();
	uint8_t Key_toggle_state(uint8_t state);

	/* 输入0，key released 输入1.key pressed ELSE  */
	void Key_set_state(uint8_t state){
		Key_toggle_state(state);
	}


	uint8_t	Key1_State(uint8_t mode);

	uint8_t Key_is_pressed();

};

#endif /* KEY_KEY1_H_ */
