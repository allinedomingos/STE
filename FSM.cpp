#include "FSM.h"

UART uart_fsm(9600,8,0,2);

FSM::FSM(){

	this->estado = IDLE;
	this->cinto = false;
	this->sentado = false;
	this->tempo = false;
	this->buzzer = false;
	this->timer_on = false;
}


FSM::~FSM(){

}

void FSM::start_fsm(){
	switch (estado){
	case IDLE:
		uart_fsm.puts("IDLE\n");
		if(sentado==true){
			estado = SEATED;
			//Ligo meu timer
			timer_on = true;
		}else{
			estado = IDLE;
		}
		break;
	case SEATED:
		uart_fsm.puts("SEATED\n");
		if(cinto==true){
			estado = BELTED;
		}
		if(cinto==false && tempo==false){
			estado = SEATED;
		}

		if(sentado==false){
			estado = IDLE;
		}
		if(tempo==true){
			estado = BUZZER;
		}
		break;
	case BELTED:
		uart_fsm.puts("BELTED\n");
		if(cinto==false){
			timer_on = true;
			estado = SEATED;
		}
		if(sentado==false){
			estado = IDLE;

		}

		break;
	case BUZZER:
		uart_fsm.puts("BUZZER\n");
		//liga o buzzer
		buzzer_on();
		if(cinto==true){
			buzzer_off();
			estado = BELTED;

		}
		if(sentado==false){
			buzzer_off();
			estado = IDLE;
		}
		break;
	default:
		//usar a UART para fazer os prints
		uart_fsm.puts("Estado inválido\n");
	}
}
void FSM::belt(bool value){
	this->cinto = value;
}

bool FSM::get_belt(){
	return this->cinto;
}
void FSM::seat(bool value){
	this->sentado = value;
}

bool FSM::get_seat(){
	return this->sentado;
}
void FSM::timer(bool value){
	this->tempo = value;
}

bool FSM::get_timer_on(){
	return this->timer_on;
}
bool FSM::set_timer_on(bool v){
	this->timer_on=v;
}

void FSM::buzzer_on(){
	if(this->buzzer){
				//mantem ligado
		}else{
			this->buzzer = true;
		}


}
void FSM::buzzer_off(){

	if(this->buzzer){
			//desliga
			this->buzzer = false;
		}

}

bool FSM::get_buzzer(){
	return this->buzzer;
}


