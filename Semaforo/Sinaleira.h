/*
 * Sinaleira.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */


#ifndef SEMAFORO_SINALEIRA_H_
#define SEMAFORO_SINALEIRA_H_

class Sinaleira {
	Pista leste_oeste_central;

	Sinaleira() {


	}

	Sinaleira leste_oeste1 () {
		if(leste_oeste_central->tamanhoSobra() <= 7) {

		}
	}


	~Sinaleira() {

	}
protected:
	int relogio;
	bool aberto;
};

#endif /* SEMAFORO_SINALEIRA_H_ */
