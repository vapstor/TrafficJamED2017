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
#include "../Estruturas/linked_list.h"

/* Visão Esquemática:
	Verde Para Oeste - Transição - Fecha

*/

namespace structures {

template <typename T>
	class Sinaleira : listaPistas<T>, LinkedList<T>{
		Sinaleira() {
			aberto = false;
			pistasPossiveisS1 = new LinkedList<T>; //Listas das Pistas que se Pode Virar a partir de uma qualquer no S1
			pistasPossiveisS2 = new LinkedList<T>; //Listas das Pistas que se Pode Virar a partir de uma qualquer no S2
			probVirarS1 = new LinkedList<T>; //Listas das Pistas A Virar S1
			probVirarS2 = new LinkedList<T>; //Listas das Pistas A Virar S2
			relogio = 0;
		}

		typename LinkedList<T> getPistasPossiveis(Pista p) {

			//! Limpa Pistas Possíveis antes de construir
			pistasPossiveisS1.clear();
			pistasPossiveisS2.clear();

			//! Declara Pistas Fontes Possiveis Esquerda
			opcao1 = listaPistas<T>::PistaFonte<T> O1leste;
			opcao2 = listaPistas<T>::PistaFonte<T> S1norte;
			opcao3 = listaPistas<T>::PistaFonte<T> N1sul;

			//! Declara Pistas Fontes Possiveis Direita
			opcao4 = listaPistas<T>::PistaFonte<T> L1oeste;
			opcao5 = listaPistas<T>::PistaFonte<T> S2norte;
			opcao6 = listaPistas<T>::PistaFonte<T> N2sul;

			//! Declara Pistas Centrais
			opcao7 = listaPistas<T>::Pista<T> C1leste;
			opcao8 = listaPistas<T>::Pista<T> C1oeste;

			//! Compara Pistas Para descobrir Qual É e Assimilar Probabilidades
			switch (p) {
				case opcao1:
					pistasPossiveisS1.push_back(C1leste); //80
					pistasPossiveisS1.push_back(S1sul); //10
					pistasPossiveisS1.push_back(N1norte); //10
					paraOndeVirars1();
					break;
				case opcao2:
					pistasPossiveisS1.push_back(C1leste); //80
					pistasPossiveisS1.psuh_back(N1norte); //10
					pistasPossiveisS1.push_back(O1oeste); //10
					paraOndeVirars1();
					break;
				case opcao3:
					pistasPossiveisS1.push_back(C1leste); //80
					pistasPossiveisS1.push_back(O1oeste); //10
					pistasPossiveisS1.push_back(S1sul); //10
					paraOndeVirars1();
					break;
				case opcao4:
					pistasPossiveisS2.push_back(N2norte); //40
					pistasPossiveisS2.push_back(S2sul); //30
					pistasPossiveisS2.push_back(C1leste); //30
					paraOndeVirars2();
					break;
				case opcao5:
					pistasPossiveisS2.push_back(L1leste); //40
					pistasPossiveisS2.push_back(N2norte); //30
					pistasPossiveisS2.push_back(C1oeste); //30
					paraOndeVirars2();
					break;
				case opcao6:
					pistasPossiveisS2.push_back(C1oeste); //40
					pistasPossiveisS2.push_back(L1leste); //30
					pistasPossiveisS2.push_back(S2sul); //30
					paraOndeVirars2();
					break;
				case opcao7:
					pistasPossiveisS2.push_back(L1leste); //40
					pistasPossiveisS2.push_back(N2norte); //30
					pistasPossiveisS2.push_back(S2sul); //30
					paraOndeVirars2();
					break;
				case opcao8:
					pistasPossiveisS1.push_back(O1oeste); //40
					pistasPossiveisS1.push_back(N1norte); //30
					pistasPossiveisS1.push_back(S1sul); //30
					paraOndeVirars1Except();
					break;
			}

			if(pistasPossiveisS1.head == NULL) {
				return pistasPossiveisS2;
			}
			if (pistasPossiveisS2.head == NULL) {
				return pistasPossiveisS1;
			} else {
				throw std::out_of_range("Erro nas Pistas Possíveis [Sinaleira]");
			}
		} //! Fim Pistas Possiveis

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
	protected:
		int relogio;
		bool aberto;
		Sinaleira s1, s2;

		typename LinkedList<T> pistasPossiveisS1;
		typename LinkedList<T> pistasPossiveisS2;
		typename LinkedList<T> probVirarS1;
		typename LinkedList<T> probVirarS2;
		typename listaPistas<T>::Pista<T> opcao1, opcao2, opcao3, opcao4, opcao5, opcao6, opcao7, opcao8;
	};
}
#endif /* SEMAFORO_SINALEIRA_H_ */
