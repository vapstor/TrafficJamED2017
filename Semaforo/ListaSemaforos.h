/*
 * ListaSemaforos.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */

#ifndef SEMAFORO_LISTASEMAFOROS_H_
#define SEMAFORO_LISTASEMAFOROS_H_

#include "./Estruturas/linked_list.h"
#include "Sinaleira.h"

namespace structures {

template<typename T>
//! Classe Lista Semaforos
	class ListaSemaforos : public LinkedList<T>, Sinaleira<T> {
		ListaSemaforos() {
			//! Cria Lista
			LinkedList<T>::head = NULL;
			LinkedList<T>::size_ = 0;

			//! Instancia Sinaleiras
			s1 = new Sinaleira();
			s2 = new Sinaleira();

			//! Adiciona Sinaleiras à Lista de Sinaleiras
			AdicionaSinaleirasNaLista();
		}

		void AdicionaSinaleirasNaLista() {
			LinkedList<T>::push_back(s1);
			LinkedList<T>::push_back(s2);
		}

		~ListaSemaforos() {
			LinkedList<T>::clear();
		}

	protected:
		Sinaleira s1, s2;
	};
}
#endif /* SEMAFORO_LISTASEMAFOROS_H_ */
