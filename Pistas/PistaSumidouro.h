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
			Pista<carros>::velocidadePista = v;
			Pista<carros>::tamanhoPista = s;
			carrosReciclados = 0;
		}

		int calculaTempoPercorrer(Carro<T> c) {
			tamanhoPista = tamanhoPista - (c.tamanhoCarro + c.distanciaEntreCarros());
			return (int)tamanhoPista/velocidadePista;
		}

		void fimDaFila() {
			pistaAtual = Pista<carros>::getPistaAtual();
			Carro<carros> CarroDeletar = pistaAtual.at(0);
			int relogio = RelogioSistema<carros>::relogio;
			if (relogio >= calculaTempoPercorrer(carroDeletar)) {
				Carro<carros> CarroFimFila = pistaAtual.deletaCarro();
			}
			carrosReciclados++;
		}
	protected:
		Pista<carros> pistaAtual;
		int carrosReciclados;
	};

}


#endif /* PISTAS_PISTASUMIDOURO_H_ */
