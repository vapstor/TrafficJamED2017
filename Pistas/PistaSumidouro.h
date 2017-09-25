/*
 * PistasEferentes.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef PISTAS_PISTASUMIDOURO_H_
#define PISTAS_PISTASUMIDOURO_H_
#include "../Estruturas/array_list.h"
#include "Pista.h";
#include "listaPistas.h"
#include "./Relogio/RelogioSistema.h"

namespace structures {

template<typename carros>
	class PistaSumidouro : Pista<carros>, RelogioSistema<carros> {
	public:
		PistaSumidouro (double v, int s) {
			velocidadePista = v;
			tamanhoPista = s;
		}

		int calculaTempoPercorrer(Carro<T> c) {
			tamanhoPista = tamanhoPista - (c.tamanhoCarro + c.distanciaEntreCarros());
			return (int)tamanhoPista/velocidadePista;
		}

		void fimDaFila(Pista<carros> pistaAtual) {
			if (RelogioSistema<carros>::relogio >= calculaTempoPercorrer(pistaAtual::at(0))) {

			}
		}
	protected:
		double velocidadePista;
		int tamanhoPista;
	};

}


#endif /* PISTAS_PISTASUMIDOURO_H_ */
