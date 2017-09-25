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
#include "../Pistas/Pistas.h"
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
		}

		//! Probabilidades baseadas num calculo de 1-10
		void paraOndeVirars1() {
			srand(time(NULL));
			int numero = 0;
			int aleatorio = rand() % 10 + 1;
			if(aleatorio >= 1 && Aleatorio < 2) {
				probVirarS1.push_back(pistasPossiveisS1.at(1)); //10
			}
			if(aleatorio >= 2 && Aleatorio < 3) {
				probVirarS1.push_back(pistasPossiveisS1.at(2)); //10
			}
				probVirarS1.push_back(pistasPossiveisS1.at(0)); //80
		}

		void paraOndeVirars1Except() {
			srand(time(NULL));
			int numero = 0;
			int aleatorio = rand() % 10 + 1;
			if(aleatorio >= 1 && aleatorio <= 4) {
				probVirarS1.push_back(pistasPossiveisS1.at(0)); //40
			}
			if(aleatorio > 4 && aleatorio <=7) {
				probVirarS1.push_back(pistasPossiveisS1.at(1)); //30
			}
			probVirarS1.push_back(pistasPossiveisS1.at(2)); //30
		}

		void paraOndeVirars2() {
			srand(time(NULL));
			int numero = 0;
			int aleatorio = rand() % 10 + 1;
			if(aleatorio >= 1 && Aleatorio <= 4) { //40
				probVirarS2.push_back(pistasPossiveisS1.at(0));
			}
			if(aleatorio > 4 && Aleatorio <= 7) { //30
				probVirarS2.push_back(pistasPossiveisS1.at(1));
			}
			probVirarS2.push_back(pistasPossiveisS1.at(2));
		}
		//! Fim probabilidades

		LinkedList<pistas> getPistasEferentes() {
			return Pista<carro>::listaPistasSaida(SinaleiraDaPista);
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
		Pista SinaleiraDaPista;
		int relogio;
		bool aberto;

	};
}
#endif /* SEMAFORO_SINALEIRA_H_ */
