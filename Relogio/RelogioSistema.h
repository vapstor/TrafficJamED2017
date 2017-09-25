/*
 * RelogioSistema.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

//! Lista de Eventos Ordenada

#ifndef RELOGIO_RELOGIOSISTEMA_H_
#define RELOGIO_RELOGIOSISTEMA_H_
#include "../Estruturas/linked_list.h"
#include "../Semaforo/ListaSemaforos.h"
#include "../Veiculo/Carro.h"
#include "../Pistas/listaPistas.h"
#include "../Pistas/Pista.h"

namespace structures {

template <typename T>

class RelogioSistema : LinkedList<T>, ListaSemaforos<T>, Carro<T>, listaPistas<T>{
	public:
		RelogioSistema() {
			relogio = 0;
		}



		void inserirCarro() {
			c = new Carro();

		}

		mudancaEstadoSemaforo();



		void carroNoSemaforo() {
			int tempoPraChegar = calculaTempoPercorrer();

			if (pode cruzar)x

		}


		int calculaTempoPercorrer(double v, int t) {
			t = t - (c.tamanhoCarro + c.distanciaEntreCarros());
			return (int)t/v;
		}


		void trocaPista() {
			Pista<T> PistaDestino
			Pista<carros>::head->mext(PistaDestino.tail);
			int velocidadeDestino = Pista<T>.velocidadePista;
		}

	protected:
		Carro<T> c;
		Pista<carros> p;
		int relogio;
	};
}


#endif /* RELOGIO_RELOGIOSISTEMA_H_ */
