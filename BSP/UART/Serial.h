/*
 * Serial.h
 *
 *  Created on: May 16, 2023
 *      Author: Shiwe
 */

#ifndef UART_SERIAL_H_
#define UART_SERIAL_H_

#define REC_LENGTH 1
#define MAX_REC_LENGTH 2048


class Serial {
public:
	Serial();
	virtual ~Serial();
	void sendData();
	void receiveData();

};

#endif /* UART_SERIAL_H_ */
