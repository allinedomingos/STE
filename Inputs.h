#include "FSM.h"
#include "GPIOPin.h"
#include <avr/interrupt.h>
#ifndef Inputs_H_
#define Inputs_H_

class Inputs{
public:
	Inputs(FSM * fsm);
	~Inputs();
	void Seat();
	void Belt();


private:
	FSM * fsm_object;

};
#endif
