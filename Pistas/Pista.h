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
#include "./Veiculo/Onibus.h"

namespace structures {

template<typename T>
	//! Classe Pista [!sumidouro] (Fila de Vetor)
	class Pista : public ArrayQueue<T>{

		Pista(double vel, int tam) {
			tamanhoPista = tam;
			velocidadePista = vel;
			espacoOcupado = 0;
		}

		//! Se o tamanho ocupado+tamanho que o carro ocupa ainda for menor que o tamanho da pista, adiciona carro
		void adicionaCarro(Carro<T> c) {
			int i = espacoOcupado;
			int tamanhoCarroOcupa = c.tamanho + c.distanciaEntreCarros();
			i = i + tamanhoCarroOcupa;
			if (i < tamanhoPista) {
				Pista<T>::enqueue(c);
			}
		}

		void adicionaOnibus(Onibus<T> o) {
			int i = espacoOcupado;
			int tamanhoCarroOcupa = o.tamanho + o.distanciaEntreCarros();
			i = i + tamanhoCarroOcupa;
			if (i < tamanhoPista) {
				Pista<T>::enqueue(c);
			}
		}

	protected:
		double velocidadePista;
		int tamanhoPista;
		int espacoOcupado;
	};
}  //! namespace structures

#endif /* PISTAS_PISTA_H_ */
