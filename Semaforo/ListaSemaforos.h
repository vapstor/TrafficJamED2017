/*
 * ListaSemaforos.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */

#ifndef SEMAFORO_LISTASEMAFOROS_H_
#define SEMAFORO_LISTASEMAFOROS_H_

#include "./Estruturas/linked_list.h"
#include "./Pistas/listaPistas.h"
#include "Sinaleira.h"

namespace structures {

//!uma fila num semaforo - semaforo na outra fila;

template<typename sinaleiras>
//! Classe Lista Semaforos
	class ListaSemaforos : public LinkedList<sinaleiras> {
		ListaSemaforos() {
			//! Cria Lista
			LinkedList<sinaleiras>::head = NULL;
			LinkedList<sinaleiras>::size_ = 0;

			//! Instancia Sinaleiras S1
			S1Norte = new Sinaleira(listaPistas<pistas>::S1norte);
			S1leste = new Sinaleira(listaPistas<pistas>::O1oeste);
			S1Oeste = new Sinaleira(listaPistas<pistas>::C1oeste);
			S1Sul = new Sinaleira(listaPistas<pistas>::N1sul);

			// Instancia Sinaleira S2
			S2Norte = new Sinaleira(listaPistas<pistas>::S2norte);
			S2Leste = new Sinaleira(listaPistas<pistas>::C1leste);
			S2Sul = new Sinaleira(listaPistas<pistas>::N2sul);
			S2Oeste = new Sinaleira(listaPistas<pistas>::L1oeste);

			//! Adiciona Sinaleiras à Lista de Sinaleiras
			AdicionaSinaleirasNaLista();
		}

		void AdicionaSinaleirasNaLista() {
			LinkedList<sinaleiras>::push_back(S1Norte);
			LinkedList<sinaleiras>::push_back(S1leste);
			LinkedList<sinaleiras>::push_back(S1sul);
			LinkedList<sinaleiras>::push_back(S1Oeste);
			LinkedList<sinaleiras>::push_back(S2Norte);
			LinkedList<sinaleiras>::push_back(S2leste);
			LinkedList<sinaleiras>::push_back(S2Sul);
			LinkedList<sinaleiras>::push_back(S2Oeste);
		}



		~ListaSemaforos() {
			LinkedList<sinaleiras>::clear();
		}

	protected:
		Sinaleira S1Norte, S1leste, S1sul, S1Oeste, S2Norte, S2Leste, S2Sul, S2Oeste;
	};
}
#endif /* SEMAFORO_LISTASEMAFOROS_H_ */
