/*
 * UART.cpp
 *
 *  Created on: 21 de ago de 2017
 *      Author: aluno
 */

#include "UART.h"
#include "Fila.h"
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>

UART * UART::singleton;


UART::UART(long baud_rate , int data_bit , int stop_bit , int paridade) {

	singleton = this;
	// configuração do baud_rate
	UBRR0 = (F_CPU / (16l*baud_rate)) - 1; // representação long (l);

	// enabling TX and Rx e habilita interrupção no receptor da UART
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	// Set frame format 8N2
	//Este registrador deve ser configurado de acordo com os parametros
	UCSR0C = (1 << USBS0) | (3 << UCSZ00);

	//Habilitando interrupção da Recepção
	UCSR0B |= (1 << RXCIE0);



}


UART::~UART() {
	singleton = 0;
}

void UART::put(char c){
		while(fila_tx.cheia()); //Espero terminar a fila encher
		fila_tx.push(c);
		//Habilitando interrupção da Transmissao So habilitar quando tiver algo p/ enviar
		UCSR0B |= (1 <<  UDRIE0);

}

void UART::udre_isr_handler(){
	if(fila_tx.vazia()){
		// Desabilita interrupção no transmissor quando nao tem mais nada para enviar
		UCSR0B |= ~(1 <<  UDRIE0);
	}else{
		char c = fila_tx.pop();
		UDR0 = c;
	}





}

void UART::rxc_isr_handler(){

	char c = UDR0;
	fila_rx.push(c);


}

char UART::get() {
//	if(fila_rx.vazia()){
//		UCSR0B |= ~(1 << RXCIE0);
//	}else
	while(fila_rx.vazia());
		return fila_rx.pop();








}


void UART::puts(const char *s){
	while(*s) {
		put(*s);
		s++;

	}


}
//Aconteceu a interrupcao no receptor
ISR(USART_RX_vect){

	UART::singleton->rxc_isr_handler();
}

//Aconteceu a interrupcao no transmissor
ISR(USART_UDRE_vect){
	UART::singleton->udre_isr_handler();
}


