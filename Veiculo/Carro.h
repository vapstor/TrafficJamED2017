/*
 * Carro.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */

#ifndef VEICULO_CARRO_H_
#define VEICULO_CARRO_H_

class Carro {
	Carro() {
		tamanhoVeiculo = 5;
		espacoAtras = 2;
		espacoFrente = 1;
	}

	int getTamanho() {
		tamanhoVeiculo
	}

	~Carro() {
		// TODO Auto-generated destructor stub
	}
protected:
	int tamanhoVeiculo;
	int espacoAtras;
	int espacoFrente;
};

#endif /* VEICULO_CARRO_H_ */
