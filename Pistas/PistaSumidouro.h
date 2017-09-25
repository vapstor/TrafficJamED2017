/*
 * PistasEferentes.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef PISTAS_PISTASUMIDOURO_H_
#define PISTAS_PISTASUMIDOURO_H_
#include "../Estruturas/linked_list.h"
#include "Pista.h";
#include "listaPistas.h"

namespace structures {

template<typename T>
	class PistaSumidouro : Pista<T>{
	public:
		PistaSumidouro (double v, int s) {
			velocidadePista = v;
			tamanhoPista = s;
		}


	protected:
		double velocidadePista;
		int tamanhoPista;
	};

}


#endif /* PISTAS_PISTASUMIDOURO_H_ */
