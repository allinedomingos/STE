#include "UART.h"
#include <avr/interrupt.h>
#ifndef FSM_H_
#define FSM_H_

class FSM {
public:
	enum ESTADO{
		IDLE,
		SEATED,
		BELTED,
		BUZZER,


	};


	FSM();
	~FSM();
	void start_fsm();
	void seat(bool value);
	bool get_seat();
	void timer(bool value);
	bool get_timer_on();
	bool set_timer_on(bool v);
	void belt(bool value);
	bool get_belt();
	void buzzer_on();
	void buzzer_off();
	bool get_buzzer();
	bool get_time();






private:
	ESTADO estado;
	bool sentado;
	bool tempo;
	bool cinto;
	bool buzzer;
	bool timer_on;




};
#endif
