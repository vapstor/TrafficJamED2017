/*
 * Sinaleira.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */


#ifndef SEMAFORO_SINALEIRA_H_
#define SEMAFORO_SINALEIRA_H_
#include <stdexcept>  // C++ Exceptions
#include "../Pistas/listaPistas.h"
#include "../Pistas/Pista.h"
#include "../Estruturas/linked_list.h"

/* Visão Esquemática:
	Verde Para Oeste - Transição - Fecha

*/

namespace structures {

template <typename T>
	class Sinaleira : listaPistas<T>, LinkedList<T>, Pista<T>{
		Sinaleira(Pista p) {
			SinaleiraDaPista = p;
			aberto = false;
			relogio = 0;
			PistasEferentes = listaPistasSaida(SinaleiraDaPista);
		}

		//! Possíveis Pistas de Entrada na Sinaleira
		LinkedList<pistas> getPistasAferentes() {
			listaPistas<pistas> opcao1, opcao2;
			LinkedList<pistas> pistasAferentes;

			//! Declara Pistas Centrais
			opcao1 = listaPistas<pistas>::Pista<T> C1oeste;
			opcao2 = listaPistas<pistas>::Pista<T> C1leste;

			//! Compara Pistas Para descobrir Aferentes
			switch (SinaleiraDaPista) {
				case opcao1:
					pistasAferentes.push_back(L1oeste);
					pistasAferentes.push_back(N2sul);
					pistasAferentes.push_back(S2norte);
					break;
				case opcao2:
					pistasAferentes.push_back(S1norte);
					pistasAferentes.psuh_back(N1sul);
					pistasAferentes.push_back(O1oeste);
					break;
			}
			return pistasAferentes;
		} //! Fim Pistas Aferentes


	protected:
		LinkedList<pistas> PistasEferentes;
		Pista SinaleiraDaPista;
		int relogio;
		bool aberto;

	};
}
#endif /* SEMAFORO_SINALEIRA_H_ */
