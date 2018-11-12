/*
 * UART.h
 *
 *  Created on: 21 de ago de 2017
 *      Author: aluno
 */

#ifndef UART_H_
#define UART_H_

#include "Fila.h"

class UART {
public:
	UART(long baud_rate , int data_bit , int stop_bit , int paridade);
	~UART();
	void put(const char c);
	char get();
	void puts(const char * s);
	void rxc_isr_handler();
	void udre_isr_handler();
	static UART * singleton;



private:
	Fila<char, 8> fila_tx; //Fila de 8 posicoes
	Fila<char, 16> fila_rx; //Fila 16 posicoes



};




#endif /* UART_H_ */
