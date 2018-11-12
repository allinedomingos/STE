/*
 * main.cc

 *
 *  Created on: 14 de ago de 2017
 *      Author: aluno
 */


#include <avr/io.h>
#include<stdio.h>
#include <util/delay.h>
#include "UART.h"
#include "Timer.h"
#include <avr/interrupt.h>
#include "Buzzer.h"
#include "FSM.h"
#include "Inputs.h"
#include "Tempo.h"



UART uart_main(9600,8,0,2);
FSM maquina;
Inputs entradas(&maquina);
Buzzer led_b(&maquina);
Tempo tempo(&maquina);


int main(){
	sei();
	while(1){
		//Processos de Input
		entradas.Seat();
		entradas.Belt();
		//Maquina
		maquina.start_fsm();
		//Timer
		tempo.Start_time();
		tempo.Timer_over();
		//Buzzer
		led_b.buzzer();
		//delay
		tempo.delay();


	}

}



