#include "GPIOPin.h"
#include "FSM.h"
#ifndef Buzzer_H_
#define Buzzer_H_

class Buzzer {
	public:
	Buzzer(FSM *fsm);
	~Buzzer();
	void buzzer();
	private:
	FSM * fsm_object;

};
#endif
