/*
 * PistaFonte.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef PISTAS_PISTAFONTE_H_
#define PISTAS_PISTAFONTE_H_
#include "Pista.h"
#include "./listaPistas.h"
#include "../Veiculo/Carro.h"
#include "../Relogio/RelogioSistema.h"
#include "./geradorValoresAleatorio/Gerador.h"

namespace structures {

template <typename carros>
	class PistaFonte : Pista<carros>, RelogioSistema<carros>{
		public:
			PistaFonte(double v, int t, int li, int ls) {
				velocidadePista = v;
				Pista<T>::tamanho = t;
				novoCarro = new Carro();
				varianciaFonte = calculaVariancia(li, ls);
			}

			int calculaVariancia(int limiteInferior, int limiteSuperior) {
				return Gerador<carros>::numAleatorio(limiteInferior, limiteSuperior);
			}

			void adicionaCarro(Carro<carros> c, int v) {
				novoCarro = c;
				varianciaFonte = v;
				int time = RelogioSistema<carros>::tempoSimulacao;
				if(varianciaFonte >= time) {
					this->enqueue(novoCarro);
				}
			}

		protected:
			Carro<carros> novoCarro;
			double velocidadePista;
			int tamanho;
			int varianciaFonte;
	};
}


#endif /* PISTAS_PISTAFONTE_H_ */
