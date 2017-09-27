/*
 * ListaSemaforos.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */

#ifndef SEMAFORO_LISTASEMAFOROS_H_
#define SEMAFORO_LISTASEMAFOROS_H_

#include "../Estruturas/linked_list.h"
//#include "../Pistas/listaPistas.h"
#include "Sinaleira.h"

namespace structures {

//!uma fila num semaforo - semaforo na outra fila;

template<typename T>
//! Classe Lista Semaforos
	class ListaSemaforos : public LinkedList<T>, Sinaleira<T> {

		ListaSemaforos() {
			//!instancia Sinaleiras
			instanciaSinaleiras();
			//! Adiciona Sinaleiras à Lista de Sinaleiras
			AdicionaSinaleirasNaLista();
		}

		void instanciaSinaleiras() {
			//! Instancia Sinaleiras Esquerda
			S1Norte = new Sinaleira<T>();
			S1Leste = new Sinaleira<T>();
			S1Oeste = new Sinaleira<T>();
			S1Sul = new Sinaleira<T>();

			// Instancia Sinaleira S2
			S2Norte = new Sinaleira<T>();
			S2Leste = new Sinaleira<T>();
			S2Sul = new Sinaleira<T>();
			S2Oeste = new Sinaleira<T>();
		}

		void AdicionaSinaleirasNaLista() {
			LinkedList<T>::push_back(S1Norte);
			LinkedList<T>::push_back(S1Leste);
			LinkedList<T>::push_back(S1Sul);
			LinkedList<T>::push_back(S1Oeste);
			LinkedList<T>::push_back(S2Norte);
			LinkedList<T>::push_back(S2Leste);
			LinkedList<T>::push_back(S2Sul);
			LinkedList<T>::push_back(S2Oeste);
		}

		int quantidadeSinaleiras() {
			return LinkedList<T>::size_;
		}

		Sinaleira<T> nextSinaleira() {
			return LinkedList::Node::next();
		}

	protected:
		Sinaleira<T> S1Norte, S1Leste, S1Sul, S1Oeste, S2Norte, S2Leste, S2Sul, S2Oeste;
	};
}
#endif /* SEMAFORO_LISTASEMAFOROS_H_ */
