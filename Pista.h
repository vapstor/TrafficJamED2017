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
#include "../Estruturas/array_queue.h" //! Fila Encadeada
#include "../Semaforo/Sinaleira.h"
#include "../Semaforo/ListaSemaforos.h"
#include "../Pistas/listaPistas.h"
#include "../Veiculo/Carro.h"
#include "../Estruturas/array_list.h"

namespace structures {

template<typename T>
	//! Classe Pista (Fila de Vetor)

// : public virtual ArrayQueue<T>, Sinaleira<T>, ListaSemaforos<T>, listaPistas<T>, Carro<T>
class Pista : ArrayQueue<T> {
	public:
		Pista(double vel, int tam) {
			tamanhoPista = tam;
			velocidadePista = vel;
			espacoOcupado = 0;
			i = 0;
		}

		//! Se o tamanho ocupado+tamanho que o carro ocupa ainda for menor que o tamanho da pista, adiciona carro (enqueue)
			void adicionaCarro(Carro<T> c) {
			if(!full()) {
				int e = espacoOcupado;
				int tamanhoCarroOcupa = c.tamanho + c.distanciaEntreCarros();
				e = e + tamanhoCarroOcupa;
				if (e < tamanhoPista) {
					this->enqueue(c);
					espacoOcupado = espacoOcupado+e;
				}
			} else {
				//Sinaleira->PistaDestinoCheia (?)
				//Tranca Pista
			}
		}

		//! Método deleta Carro (dequeue)
			Carro<T> deletaCarro() {
//				Pista<T> pistaAtual = getPistaAtual(); //! <- isso ou:

				Carro<T> carroVolta = this->dequeue();
				espacoOcupado = espacoOcupado-(carroVolta.tamanhoCarro - carroVolta.distanciaEntreCarros());
				return carroVolta;
			}

		//! Metodo Pista Cheia
			virtual bool full() {
				return tamanhoPista > espacoOcupado+7; //! minimo tamanho carro(4) + 3 de espaço
			}

		//! Assimiliar Listas Eferentes às Filas (não sei pq se tem a sinaleira)
			LinkedList<T> PistasSaida() {
				switch (this) {
					case N1sul:
						ListaPistasPossiveis.push_back(C1leste); //80
						ListaPistasPossiveis.push_back(O1oeste); //10
						ListaPistasPossiveis.push_back(S1sul); //10
						break;
					case O1leste:
						ListaPistasPossiveis.push_back(C1leste); //80
						ListaPistasPossiveis.push_back(S1sul); //10
						ListaPistasPossiveis.push_back(N1norte); //10
						break;
					case S1norte:
						ListaPistasPossiveis.push_back(C1leste); //80
						ListaPistasPossiveis.push_back(N1norte); //10
						ListaPistasPossiveis.push_back(O1oeste); //10
						break;
					case C1oeste:
						ListaPistasPossiveis.push_back(O1oeste); //40
						ListaPistasPossiveis.push_back(S1Sul); //30
						ListaPistasPossiveis.push_back(N1norte); //30
						break;
					case N2Sul:
						ListaPistasPossiveis.push_back(L1leste); //40
						ListaPistasPossiveis.push_back(C1oeste); //30
						ListaPistasPossiveis.push_back(S2sul); //30
						break;
					case C1leste:
						ListaPistasPossiveis.push_back(L1leste); //40
						ListaPistasPossiveis.push_back(N2norte); //30
						ListaPistasPossiveis.push_back(S2sul); //30
						break;
					case S2norte:
						ListaPistasPossiveis.push_back(L1leste); //40
						ListaPistasPossiveis.push_back(C1oeste); //30
						ListaPistasPossiveis.push_back(S2sul); //30
						break;
					case L1oeste:
						ListaPistasPossiveis.push_back(N2norte); //40
						ListaPistasPossiveis.push_back(C1leste); //30
						ListaPistasPossiveis.push_back(S2sul); //30
						break;
				}
				return ListaPistasPossiveis;
	}

		//! Retorna Pista Atual
			Pista<T> getPistaAtual() {
				return this;
			}

		//! Decidir qual das 3 Possibilidades Ir
			Pista<T> pistaParaInserir(Sinaleira<T> sinaleiraAtual) {
			if(			sinaleiraAtual == ListaSemaforos<T>::S1leste
					||  sinaleiraAtual == ListaSemaforos<T>::S1sul
					||  sinaleiraAtual == ListaSemaforos<T>::S1Norte
					) {
				return calcula_prob_1();
			}
			return calcula_prob_2();
		}

		//! Probabilidades baseadas num calculo de 1-10
			Pista<T> calcula_prob_1 () {
			srand(time(NULL));
			int numero = 0;
			int aleatorio = rand() % 10 + 1;
			if(aleatorio >= 1 && aleatorio <=8) {
				return pistasPossiveis.at(0); //80%
			}
			if(aleatorio > 8 && aleatorio <= 9) {
				return pistasPossiveis.at(1); //10
			}
				return pistasPossiveis.at(2); //10
		}

			Pista<T> calcula_prob_2() {
			srand(time(NULL));
			int numero = 0;
			int aleatorio = rand() % 10 + 1;
			if(aleatorio >= 1 && aleatorio <= 4) {
				return pistasPossiveis.at(0); //40
			}
			if(aleatorio > 4 && aleatorio <=7) {
				return pistasPossiveis.at(1); //30
			}
			return pistasPossiveis.at(2); //30
		}
		//! Fim probabilidades

		Carro<T> carroNoIndice(int index) {
			return ArrayQueue<T>::at(index);
		}
	public:
		//! Descobre quais pistas pode Ir
		LinkedList<T> ListaPistasPossiveis;
		//!
		LinkedList<T> pistasPossiveis = Sinaleira<T>::getPistasSaida();

		double velocidadePista;
		int tamanhoPista;
		int espacoOcupado;
		int i;
	};
};  //! namespace structures

#endif /* PISTAS_PISTA_H_ */
