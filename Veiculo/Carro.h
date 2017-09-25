/*
 * Carro.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */

#ifndef VEICULO_CARRO_H_
#define VEICULO_CARRO_H_

namespace structures {

template <typename T>

class Carro {
	public:
		Carro() {
			tamanho = 4;
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
		int tamanho;
		int sSegurancaFrente;
		int sSegurancaAtras;
	};

}
#endif /* VEICULO_CARRO_H_ */
