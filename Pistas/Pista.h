/*
 * Pista.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef PISTAS_PISTA_H_
#define PISTAS_PISTA_H_

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./Estruturas/array_queue.h" //! Fila Encadeada
#include "./Veiculo/Carro.h"
#include "./Semaforo/Sinaleira.h"
namespace structures {

template<typename carros>
	//! Classe Pista [!sumidouro] (Fila de Vetor)
	class Pista : public ArrayQueue<carros>{

		Pista(double vel, int tam) {
			tamanhoPista = tam;
			velocidadePista = vel;
			espacoOcupado = 0;
			i = 0;
		}

		//! Se o tamanho ocupado+tamanho que o carro ocupa ainda for menor que o tamanho da pista, adiciona carro
		void adicionaCarro(Carro<T> c) {
			Pista p = pistaParaInserir();
			int i = espacoOcupado;
			int tamanhoCarroOcupa = c.tamanho + c.distanciaEntreCarros();
			i = i + tamanhoCarroOcupa;
			if (i < tamanhoPista) {
				p.enqueue(c);
			}
		}

		LinkedList<pistas> listaPistasSaida(Pista p) {
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

		Pista pistaParaInserirS1() {
			Pista PistaSeguinte;
			if (i == 0) {
				PistaSeguinte = Sinaleira<T>::probVirarS1.at(0);
				i = 1;
			}
			if (i == 1) {
				PistaSeguinte = Sinaleira<T>::probVirarS1.at(1);
				i = 2;
			}
			if (i == 2) {
				PistaSeguinte = Sinaleira<T>::probVirarS1.at(2);
				i = 0;
			}
			return PistaSeguinte;
		}

		Pista pistaParaInserirS2() {
					Pista PistaSeguinte;
					if (i == 0) {
						PistaSeguinte = Sinaleira<T>::probVirarS1.at(0);
						i = 1;
					}
					if (i == 1) {
						PistaSeguinte = Sinaleira<T>::probVirarS1.at(1);
						i = 2;
					}
					if (i == 2) {
						PistaSeguinte = Sinaleira<T>::probVirarS1.at(2);
						i = 0;
					}
					return PistaSeguinte;
		}

	protected:

		LinkedList<pistas> pistasPossiveisS1;
		LinkedList<pistas> pistasPossiveisS2;
		LinkedList<pistas> probVirarS1;
		LinkedList<pistas> probVirarS2;
		listaPistas<pistas> opcao1, opcao2, opcao3, opcao4, opcao5, opcao6, opcao7, opcao8;
		double velocidadePista;
		int tamanhoPista;
		int espacoOcupado;
		int i;
	};
}  //! namespace structures

#endif /* PISTAS_PISTA_H_ */
