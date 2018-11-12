/*
 * GPIOPin.cpp
 *
 *  Created on: 14 de ago de 2017
 *      Author: aluno
 */

#include "GPIOPin.h"
#include <avr/io.h>
#include <util/delay.h>


GPIO_Pin::GPIO_Pin(int p, DDR d) {

	if((p>=8) && (p<=13)){
		_pin = (p-8);
		_pointer = (gpio_regs_t *) 0x23;

	}

	if((p>=0) && (p<=7)){
		_pin = p;
		_pointer = (gpio_regs_t *)0x29;

	}

	if((p>=14)&& (p<=19)){
		_pin = (p-14);
		_pointer = (gpio_regs_t *)0x26;

	}

	if (d) {
		_pointer -> ddr |= (1 << _pin); //output
	} else {
		_pointer -> ddr &= ~(1 << _pin); //input
	}
}

GPIO_Pin::~GPIO_Pin() {
	// TODO Auto-generated destructor stub
}

void GPIO_Pin::on() {
	_pointer->port |= (1 << _pin);
}

void GPIO_Pin::off() {
	_pointer->port &= ~(1 << _pin);
}

GPIO_Pin::PIN_VALUE GPIO_Pin::get() {
	PIN_VALUE valor;
	if ((_pointer->pin & (1 << _pin)) > 0) {//porta 4 lê um valor e compara com 0
		valor=HIGH;
	} else {
		valor=LOW;
	}

	return valor;

}

void GPIO_Pin::set(PIN_VALUE acao){
	if (acao==HIGH){
		on();
	} else{
		off();
	}
}

