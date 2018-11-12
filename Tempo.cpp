#include "Tempo.h"
Timer timer(10000);
Tempo::Tempo(FSM*m){
	this->m = m;
}

Tempo::~Tempo(){

}

void Tempo::Start_time(){
	//verifica se a maquina iniciou contagem
	if(m->get_timer_on()){
		this->tempo_start = timer.millis();
		m->set_timer_on(false);
	}
}

void Tempo::Timer_over(){
	this->tempo_now = timer.millis(); // tempo agora

	if((this->tempo_now - this->tempo_start) > 5000){
		m->timer(true);  //atributo da maquina de estados

	}
}

void Tempo::delay(){
	timer.delay(1000);
}
