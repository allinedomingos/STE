#include "Inputs.h"



GPIO_Pin belt(9,GPIO_Pin::INPUT);
GPIO_Pin seat(8,GPIO_Pin::INPUT);


Inputs::Inputs(FSM * fsm){
	this->fsm_object = fsm;

}

Inputs::~Inputs(){

}

void Inputs::Belt(){
	GPIO_Pin::PIN_VALUE value = belt.get();
	if(value == GPIO_Pin::HIGH){
		this->fsm_object->belt(true);
	}else{
		this->fsm_object->belt(false);
	}
}

void Inputs::Seat(){
	GPIO_Pin::PIN_VALUE value = seat.get();
	if(value == GPIO_Pin::HIGH){
			this->fsm_object->seat(true);
		}else{
			this->fsm_object->seat(false);
		}
}

