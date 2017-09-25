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
	class Pista : public virtual ArrayQueue<carros>, public Sinaleira<carros> , public ListaSemaforos<carros>{

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

		Carro<carros> deletaCarro() {
			Pista<carros> pistaAtual = getPistaAtual();
			Carro<carros> carroVolta = pistaAtual.dequeue();
			espacoOcupado = espacoOcupado-(carroVolta.tamanhoCarro - carroVolta.distanciaEntreCarros());
			return carroVolta;
		}

		virtual bool full() {
			return tamanhoPista > espacoOcupado+7; //! minimo tamanho carro(4) + 3 de espaço
		}

	//! Assimiliar Listas Eferentes às Filas (não sei pq se tem a sinaleira)
	LinkedList<carros> PistasSaida() {
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

		Pista<carros> getPistaAtual() {
			return this;
		}

		//! Decidir qual das 3 Possibilidades Ir
		Pista<carros> pistaParaInserir() {
			if(			Sinaleira<carros>::getSinaleiraAtual() == ListaSemaforos<carros>::S1leste
					||  Sinaleira<carros>::getSinaleiraAtual() == ListaSemaforos<carros>::S1sul
					||  Sinaleira<carros>::getSinaleiraAtual() == ListaSemaforos<carros>::S1Norte
					) {
				return calcula_prob_1();
			}
			return calcula_prob_2();
		}

		//! Probabilidades baseadas num calculo de 1-10
		Pista<carros> calcula_prob_1 () {
			srand(time(NULL));
			int numero = 0;
			int aleatorio = rand() % 10 + 1;
			if(aleatorio >= 1 && aleatorio <=8) {
				return pistasPossiveis.at(0); //80%
			}
			if(aleatorio > 8 && Aleatorio <= 9) {
				return pistasPossiveis.at(1); //10
			}
				return pistasPossiveis.at(2); //10
		}

		Pista<carros> calcula_prob_2() {
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

	protected:
		//! Descobre quais pistas pode Ir
		LinkedList<Pista<carros>> ListapistasPossiveis;

		//!
		LinkedList<Pista<carros>> pistasPossiveis = Sinaleira<T>::getPistasSaida();


		double velocidadePista;
		int tamanhoPista;
		int espacoOcupado;
		int i;
	};
}  //! namespace structures

#endif /* PISTAS_PISTA_H_ */
