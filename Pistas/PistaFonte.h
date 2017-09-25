/*
 * PistaFonte.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef PISTAS_PISTAFONTE_H_
#define PISTAS_PISTAFONTE_H_
#include "Pista.h"
#include "listaPistas.h"

namespace structures {

template <typename T>
	class PistaFonte : Pista<T>, listaPistas<T> {
		public:
			PistaFonte(double v, int t, int f) {
				LinkedQueue<T>::head = NULL;
				LinkedQueue<T>::tail = head;
				LinkedQueue<T>::size_ = 0;
				velocidadePista = v;
				tamanho = t;
				varianciaFonte = f;
			}

		protected:
		double velocidadePista;
		int tamanho;
		int varianciaFonte;

	};
}


#endif /* PISTAS_PISTAFONTE_H_ */
