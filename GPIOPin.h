/*
 * GPIOPin.h
 *
 *  Created on: 14 de ago de 2017
 *      Author: aluno
 */
#include <avr/io.h>
#include <util/delay.h>

#ifndef GPIOPIN_H_
#define GPIOPIN_H_

class GPIO_Pin {
public:
	enum DDR{
		INPUT = 0,
		OUTPUT = 1
	};

	enum PIN_VALUE{
		LOW = 0,
		HIGH =1
	};

	GPIO_Pin(int p, DDR d);
	~GPIO_Pin();
	void on ();  //seta pra um
	void off();  //seta pra zero


	PIN_VALUE get();
	void set(PIN_VALUE acao);

private:
	struct gpio_regs_t{     // estrutura do ponteiro
		unsigned char pin;
		unsigned char ddr; // diz se pino e entrada/saída
		unsigned char port; // diz se estado do pino e alto/baixo

	};
	int _pin;
	volatile gpio_regs_t *_pointer; // 3 bites

};
#endif /* GPIOPIN_H_ */
