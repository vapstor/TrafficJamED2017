/*
 * Sinaleira.h
 *
 *  Created on: 20 de set de 2017
 *      Author: vapstor
 */


#ifndef SEMAFORO_SINALEIRA_H_
#define SEMAFORO_SINALEIRA_H_
#include "../Pistas/listaPistas.h"

namespace structures {

template <typename T>
	class Sinaleira : listaPistas<T>{
		Sinaleira() {

		}

		typename LinkedList<T> getPistasPossiveis(Pista p) {

			//! Declara Pistas Fontes Possiveis Esquerda
			opcao1 = listaPistas<T>::PistaFonte<T> O1leste;
			opcao2 = listaPistas<T>::PistaFonte<T> S1norte;
			opcao3 = listaPistas<T>::PistaFonte<T> N1norte;

			//! Declara Pistas Fontes Possiveis Direita
			opcao4 = listaPistas<T>::PistaFonte<T> L1oeste;
			opcao5 = listaPistas<T>::PistaFonte<T> S2norte;
			opcao6 = listaPistas<T>::PistaFonte<T> N2norte;


			//! Compara Pistas Para descobrir Qual É
			switch (p) {
				case opcao1:
					pistasPossiveis.push_back(C1leste);
					break;
				case opca2:
			}
		} //! Fim Pistas Possiveis


		~Sinaleira() {

		}
	protected:
		int relogio;
		bool aberto;
		Sinaleira s1, s2;

		typename LinkedList<T> pistasPossiveisS1;
		typename LinkedList<T> pistasPossiveisS2;
		typename listaPistas<T>::Pista<T> opcao1, opcao2, opcao3, opcao4, opcao5, opcao6;
	};
}
#endif /* SEMAFORO_SINALEIRA_H_ */
