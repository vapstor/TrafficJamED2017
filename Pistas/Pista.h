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
#include "./Estruturas/array_list.h"
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
		void adicionaCarro(Carro<T> c, Pista<carro> pistaDestino) {
			if(!full()) {
				int e = espacoOcupado;
				int tamanhoCarroOcupa = c.tamanho + c.distanciaEntreCarros();
				e = e + tamanhoCarroOcupa;
				if (e < tamanhoPista) {
					pistaDestino.enqueue(c);
					espacoOcupado = espacoOcupado+e;
				}
			} else {
				//?????
			}
		}

		bool full() {
			return tamanhoPista > espacoOcupado+7; //! minimo tamanho carro(4) + 3 de espaço
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

		//! Decidir qual das 3 Possibilidades do Array de Possibilidades Ir
		Pista pistaParaInserirS1() {
			Pista PistaSeguinte;
			if (i == 0) {
				PistaSeguinte = ArrayList<T> probVirarS1.at(0);
				i = 1;
			} else if (i == 1) {
				PistaSeguinte = ArrayList<T> probVirarS1.at(1);
				i = 2;
			} else if (i == 2) {
				PistaSeguinte = ArrayList<T> probVirarS1.at(2);
				i = 0;
			}
			return PistaSeguinte;
		}

		//! Decidir qual das 3 Possibilidades do Array de Possibilidades Ir
		Pista pistaParaInserirS2() {
			Pista PistaSeguinte;
				if (i == 0) {
					PistaSeguinte = ArrayList<T> probVirarS2.at(0);
					i = 1;
				} else if (i == 1) {
					PistaSeguinte = ArrayList<T> probVirarS2.at(1);
					i = 2;
				} else if (i == 2) {
					PistaSeguinte = Sinaleira<T> probVirarS2.at(2);
				i = 0;
			}
			return PistaSeguinte;
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

	protected:
		//! Descobre qual pista esta e para onde é possíve ir
		LinkedList<pistas> pistasPossiveisS1;
		LinkedList<pistas> pistasPossiveisS2;

		//! Depois de descobrir as possibilidades, calcular as probabilidades
		//! e adicionar numa lista de pistas [0,1,2]
		ArrayList<T> probVirarS1 = new ArrayList[2];
		ArrayList<T> probVirarS2 = new ArrayList[2];

		//! Declaração Pistas Possíveis de que se trata
		listaPistas<pistas> opcao1, opcao2, opcao3, opcao4, opcao5, opcao6, opcao7, opcao8;

		double velocidadePista;
		int tamanhoPista;
		int espacoOcupado;
		int i;
	};
}  //! namespace structures

#endif /* PISTAS_PISTA_H_ */
