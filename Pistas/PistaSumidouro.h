/*
 * PistasEferentes.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef PISTAS_PISTASUMIDOURO_H_
#define PISTAS_PISTASUMIDOURO_H_
#include "../Estruturas/array_list.h"
#include "Pista.h"
#include "../Veiculo/Carro.h"
#include "../Relogio/RelogioSistema.h"
#include "listaPistas.h"

namespace structures {

template<typename T>
	class PistaSumidouro : public Pista<T>, RelogioSistema<T> {
	public:
		PistaSumidouro (double v, int s) {
			velocidadePista = v;
			tamanhoPista = s;
			carrosReciclados = 0;
		}

		int calculaTempoPercorrer(Carro<T> c) {
			tamanhoPista = tamanhoPista - (c.tamanhoCarro + c.distanciaEntreCarros());
			return (int)tamanhoPista/velocidadePista;
		}

		void fimDaFila() {
			pistaAtual = Pista<T>::getPistaAtual();
			Carro<T> CarroDeletar = pistaAtual.at(0);
			int relogio = RelogioSistema<T>::relogio;
			if (relogio >= calculaTempoPercorrer(CarroDeletar)) {
				Carro<T> CarroFimFila = pistaAtual.deletaCarro();
			}
			carrosReciclados++;
		}
	protected:
		Pista<T> pistaAtual;
		double velocidadePista;
		int tamanhoPista;
		int carrosReciclados;

	};

}


#endif /* PISTAS_PISTASUMIDOURO_H_ */
