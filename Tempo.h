
#include "Timer.h"
#include "FSM.h"

#ifndef Tempo_H_
#define Tempo_H_

class Tempo{
public:
	Tempo(FSM * m);
	~Tempo();
	void Start_time();
	void Timer_over();
	void delay();

private:
	Milliseconds tempo_start;
	Milliseconds tempo_now;
	FSM * m;
};
#endif
