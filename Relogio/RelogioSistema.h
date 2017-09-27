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
class RelogioSistema : ArrayList<T>, Pista<T>, PistaFonte<T>, ListaSemaforos<T>{
	public:
		RelogioSistema(int tempo) {
			tempoSimulacao = tempo;
		}

		void inserirCarro() {
			PistaFonte<T> atual;
			for (int i = 6; i < 12; i++) { //pistas fontes
				atual = listaPistas<T>[i];
				if (atual.varianciaFonte == 1) {

				}

				//Pista pistaInsereTeste = listaPistas::S2norte;
//				pistaInsereTeste.adicionaCarro(new Carro, this);
			}
		}

		void mudaEstadoSemaforo() {
			Sinaleira<T> sinaleiraAtual = Sinaleira<T>::getSinaleiraAtual();
			if(sinaleiraAtual->aberto) {
				sinaleiraAtual->aberto = false;
			} else {
				sinaleiraAtual->aberto = true;
			}
		}

		void carroNoSemaforo() {
			Pista<T> pistaAtual = Pista<T>::getPistaAtual();
			Sinaleira<T> semaforoAtual = Sinaleira<T>::getSinaleiraAtual();
			int qntsSemaforos = ListaSemaforos<T>::quantidadeSinaleiras();
			Carro<T> carroParaTrocar = pistaAtual.deletaCarro();
//			bool pistaCheia = Sinaleira<T>::pistaDestinoCheia;
			for (int i = 0; i < qntsSemaforos; i++) {
				if (semaforoAtual->aberto && /*!pistaCheia &&*/ carroParaTrocar !=NULL) {
					trocaPista();
				} else {
					semaforoAtual = ListaSemaforos<T>::nextSinaleira();
				}
			}
			Carro<T> carroHead = Pista<T>::carroNoIndice(0);
			int s = Pista<T>::tamanhoPista;
			double v = Pista<T>::velocidadePista;
			int tempoParaPercorrer = calculaTempoPercorrer(carroHead, v, s);
			Pista<T>::listaPistasPossiveis.at();

			if (tempoSimulacao == tempoParaPercorrer) {
				carroParaTrocar = this->dequeue();
			}
			trocaPista(carroParaTrocar);
		}


		int calculaTempoPercorrer(Carro<T> c, double v, int s) {
			s = s - (c->tamanhoCarro + c.distanciaEntreCarros());
			return (int)s/v;
		}


		void trocaPista() {
			Pista<T> pistaAtual = Pista<T>::getPistaAtual();
			Carro<T> carroParaTrocar = pistaAtual.deletaCarro();
			Sinaleira<T> semaforoAtual = Sinaleira<T>::getSinaleiraAtual();
			Pista<T> pistaDestino = pistaParaInserir(semaforoAtual);

			bool sinaleiraAberta = Sinaleira<T>::aberto;
			Carro<T> carro = pistaAtual.dequeue();
			Pista<T> PistaDestino;
			//! Test Case Para Verificar Se A Pista Está Aberta

		}

	protected:
		Pista<T> p;
		int tempoSimulacao;
	};
}


#endif /* RELOGIO_RELOGIOSISTEMA_H_ */
