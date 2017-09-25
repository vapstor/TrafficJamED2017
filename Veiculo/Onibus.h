/*
 * Onibus.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef VEICULO_ONIBUS_H_
#define VEICULO_ONIBUS_H_

namespace structures {

template <typename T>

class Onibus {
	public:
		Onibus() {
			tamanho = 6;
			sSegurancaFrente = 1;
			sSegurancaAtras = 2;
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

#endif /* VEICULO_ONIBUS_H_ */
