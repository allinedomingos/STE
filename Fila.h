/*
 * Fila.h
 *
 *  Created on: 24 de ago de 2017
 *      Author: alline
 */

#ifndef FILA_H_
#define FILA_H_

template <typename T, int S> class Fila {
public:

	    Fila(){
	    	   capacidade = S;
	    	   itens = 0;
	    	   inicio = 0;
	    	   fim = 0;


	    	}
	    ~Fila(){}
	    void push(const T & algo){

	        if(!cheia()){ // se a fila não estiver cheia
	          buffer[fim] = algo; //alocar memoria no fim, acrescenta o dado
	          fim++;
	            if(fim == capacidade) fim = 0; // se a fila estiver cheia será preciso desenfileira o inicio para deslocar o fim
	             itens++;
	         }

	   }
	    T  pop(){

	        if(!vazia()){ //se a fila não estiver vazia
	          T algo;
	          algo = buffer[inicio]; //desloco memoria no inicio da fila
	          inicio++; //muda a posição do inicio da fila
	            if(inicio == capacidade) inicio = 0;
	               itens --; // como foi retirado um dado da fila, deve-se decrescer o contator.
	   	    return algo;
	         }
	   }
	    void clear(){
	    	capacidade = 0;
	    	itens = 0;
	    	inicio = 0;
	    	fim = 0;
	    }
	    bool vazia() const {return itens == 0; }
	    bool cheia() const { return itens == capacidade;}
	    unsigned int tamanho() const { return itens;}
	  private:
	    int capacidade;
	    int itens, inicio, fim;
	    T buffer[S];

};

#endif /* FILA_H_ */
