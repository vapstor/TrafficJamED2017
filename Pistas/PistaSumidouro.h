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
#include "./Veiculo/Carro.h"
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

		void fimDaFila() {
			pistaAtual = Pista<carros>::getPistaAtual();
			pistaAtual.
			if (RelogioSistema<carros>::relogio >= calculaTempoPercorrer(pistaAtual))) {
				Carro<carros> CarroFimFila = pistaAtual.deletaCarro();
			}
		}
	protected:
		double velocidadePista;
		int tamanhoPista;
		Pista<carros> pistaAtual;
	};

}


#endif /* PISTAS_PISTASUMIDOURO_H_ */
