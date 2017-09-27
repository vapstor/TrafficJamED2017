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
#include "../Semaforo/ListaSemaforos.h"
#include "../Pistas/Pista.h"
#include "../Estruturas/linked_list.h"

/* Visão Esquemática:
	Verde Para Oeste - Transição - Fecha

*/

namespace structures {

template <typename T>
class Sinaleira: ListaSemaforos<T>, listaPistas<T>{
	public:
		Sinaleira() {
			aberto = false;
			relogioDoSemaforo = 20;
			PistasSaida = getPistasSaida();
			PistasEntrada = getPistasEntrada();
		}

		LinkedList<T> getPistasSaida() {
			//! Compara Pistas Para descobrir Qual É e Assimilar Probabilidades
			switch (this) {
				case S1Norte:
					PistasSaida.push_back(C1leste); //80
					PistasSaida.push_back(O1oeste); //10
					PistasSaida.push_back(S1sul); //10
					break;
				case S1leste:
					PistasSaida.push_back(C1leste); //80
					PistasSaida.push_back(S1sul); //10
					PistasSaida.push_back(N1norte); //10
					break;
				case S1sul:
					PistasSaida.push_back(C1leste); //80
					PistasSaida.push_back(N1norte); //10
					PistasSaida.push_back(O1oeste); //10
					break;
				case S1oeste:
					PistasSaida.push_back(O1oeste); //40
					PistasSaida.push_back(S1Sul); //30
					PistasSaida.push_back(N1norte); //30
					break;
				case S2Norte:
					PistasSaida.push_back(L1leste); //40
					PistasSaida.push_back(C1oeste); //30
					PistasSaida.push_back(S2sul); //30
					break;
				case S2Leste:
					PistasSaida.push_back(L1leste); //40
					PistasSaida.push_back(N2norte); //30
					PistasSaida.push_back(S2sul); //30
				break;
				case S2sul:
					PistasSaida.push_back(L1leste); //40
					PistasSaida.push_back(C1oeste); //30
					PistasSaida.push_back(S2sul); //30
					break;
				case S2oeste:
					PistasSaida.push_back(N2norte); //40
					PistasSaida.push_back(C1leste); //30
					PistasSaida.push_back(S2sul); //30
					break;
			}
				return PistasSaida;
		}//! Fim Pistas Possiveis Saída

		//! Possíveis Pistas de Entrada na Sinaleira
		LinkedList<T> getPistasEntrada() {
			//! Compara Pistas Para descobrir Aferentes
			switch (this) {
				case S1Norte:
					PistasEntrada.push_back(N1sul);
					break;
				case S1Oeste:
					PistasEntrada.push_back(O1oeste);
					break;
				case S1Sul:
					PistasEntrada.push_back(N1Norte);
					break;
				case S1Oeste:
					PistasEntrada.psuh_back(C1oeste);
					break;
			}
			return PistasEntrada;
		} //! Fim Pistas Aferentes

		Sinaleira<T> getSinaleiraAtual() {
			return this;
		}

	protected:
		LinkedList<T> PistasEntrada;
		LinkedList<T> PistasSaida;
		int relogioDoSemaforo;
		bool aberto;
		bool pistaDestinoCheia;
	};
}
#endif /* SEMAFORO_SINALEIRA_H_ */
