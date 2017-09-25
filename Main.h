/*
 * Main.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

//! Calcular o tempo ideal para que mais carros saiam do sistema
//! Somar todos os sumidouros e ver quais simulações de semaforos deu mais tempo (qnt mais carros sairam)
//! trocar parametros dos semaforos para ver quantos entraram e sairam do sistema


#ifndef MAIN_H_
#define MAIN_H_
#include "./Veiculo/Carro.h"
#include "./Veiculo/Onibus.h"

namespace structures {
template<typename T>

class main {
public:
	main() {
		novoCarro = new Carro();
		novoOnibus = new Onibus();
	}

	protected:
	Carro novoCarro;
	Onibus novoOnibus;

	};
}
#endif /* MAIN_H_ */
