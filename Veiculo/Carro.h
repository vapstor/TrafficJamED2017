/*
 * Carro.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */

#ifndef VEICULO_CARRO_H_
#define VEICULO_CARRO_H_
#include "./geradorValoresAleatorio/Gerador.h"

namespace structures {

template <typename T>

class Carro : Gerador<T>{
	public:
		Carro() {
			tamanhoCarro = Gerador<T>::numAleatorio(4,6); //! instancia tamanho do carro entre 4,5,6
			sSegurancaFrente = 2;
			sSegurancaAtras = 1;
		}

		int espacoAtras() {
			return sSegurancaAtras;
		}

		int espacoFrente() {
			return sSegurancaFrente;
		}

		int distanciaEntreCarros() {
			return 3;
		}

	protected:
		int tamanhoCarro;
		int sSegurancaFrente;
		int sSegurancaAtras;
	};

}
#endif /* VEICULO_CARRO_H_ */
