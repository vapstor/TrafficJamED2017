/*
 * RelogioSistema.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

//! Lista de Eventos Ordenada

#ifndef RELOGIO_RELOGIOSISTEMA_H_
#define RELOGIO_RELOGIOSISTEMA_H_
#include "../Estruturas/linked_list.h"
#include "../Semaforo/ListaSemaforos.h"
#include "../Veiculo/Carro.h"
#include "../Pistas/listaPistas.h"
#include "../Pistas/Pista.h"
#include "../Semaforo/Sinaleira.h"

namespace structures {

template <typename T>

class RelogioSistema : LinkedList<T>, ListaSemaforos<T>, Pista<T>, Carro<T>, listaPistas<T>, Sinaleira<T>{
	public:
		RelogioSistema(int tempo) {
			tempoSimulacao = tempo;
		}

		void inserirCarro(Carro<T> c, Pista<carro> p) {
			Pista<T>::adicionaCarro(c, p);
		}

		void mudaEstadoSemaforo(Pista<T>) {
			if(Sinaleira<T>::aberto) {
				Sinaleira<T>::aberto = false;
			} else {
				Sinaleira<T>::aberto = true;
			}
		}

		void carroNoSemaforo() {
			Carro<T> carroHead = Pista<carros>::Pista[0];
			int s = Pista<carros>::tamanhoPista;
			double v = Pista<T>::velocidadePista;
			int tempoParaPercorrer = calculaTempoPercorrer(carroHead, v, s);
			Pista<T>::ListapistasPossiveis
			Carro<T> carroParaTrocar;
			if (relogio == tempoParaPercorrer) {
				carroParaTrocar = Pista<carros>::dequeue();
			}
			trocaPista(carroParaTrocar);
			if (pode cruzar)x

		}


		int calculaTempoPercorrer(Carro<T> c, double v, int s) {
			s = s - (c.tamanhoCarro + c.distanciaEntreCarros());
			return (int)t/v;
		}


		void trocaPista(Carro<T> carroTroca) {
			bool sinaleiraAberta = Sinaleira<T>::aberto;
			Pista<T> pistaAtual = Pista<T>::getPistaAtual();
			Carro<T> carro = pistaAtual.dequeue();
			Pista<T> PistaDestino;
			//! Test Case Para Verificar Se A Pista Está Aberta
			if (
				(pistaAtual == N1Sul && sinaleiraAberta == true)
				||
				(pistaAtual == O1leste && sinaleiraAberta == true)
				||
				(pistaAtual == S1norte && sinaleiraAberta == true)
				||
				(pistaAtual = C1oeste && sinaleiraAberta == true)
			) {
				PistaDestino = Pista<T>::;
			}
			if (pistaAtual == N2Sul || pistaAtual == C1leste || pistaAtual == S2norte || pistaAtual = L1leste) {
				PistaDestino = Pista<carros>::pistaParaInserirS1();
			}
			inserirCarro(carro, PistaDestino);
		}

	protected:
		Pista<T> p;
		int tempoSimulacao;
	};
}


#endif /* RELOGIO_RELOGIOSISTEMA_H_ */
