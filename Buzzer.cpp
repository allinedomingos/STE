#include "Buzzer.h"
#include "GPIOPin.h"

GPIO_Pin led(7,GPIO_Pin::OUTPUT);

Buzzer::Buzzer(FSM *fsm){
	this->fsm_object = fsm;
}

Buzzer::~Buzzer(){}

void Buzzer::buzzer(){
	if(this->fsm_object->get_buzzer()){
		led.on();
	}else{
		led.off();
	}


}


