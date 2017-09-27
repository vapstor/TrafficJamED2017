/*
 * PistaFonte.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef PISTAS_PISTAFONTE_H_
#define PISTAS_PISTAFONTE_H_
#include "Pista.h"
#include "../Veiculo/Carro.h"
#include "../Relogio/RelogioSistema.h"
#include "../geradorValoresAleatorio/Gerador.h"
#include "listaPistas.h"

namespace structures {

template <typename T>
	class PistaFonte : Pista<T>, RelogioSistema<T>, Carro<T>{
		public:
			PistaFonte(double v, int t, int li, int ls) {
				velocidadePista = v;
				tamanho = t;
				varianciaFonte = calculaVariancia(li, ls);
			}

			int calculaVariancia(int limiteInferior, int limiteSuperior) {
				return Gerador<T>::numAleatorio(limiteInferior, limiteSuperior);
			}

			void criaCarro(Carro<T> c, int v) {
				novoCarro = c;
				varianciaFonte = v;
				int time = RelogioSistema<T>::tempoSimulacao;
				if(varianciaFonte == time) {
					this->enqueue(novoCarro);
				}
			}

		public:
			Carro<T> novoCarro;
			double velocidadePista;
			int tamanho;
			int varianciaFonte;
	};
}


#endif /* PISTAS_PISTAFONTE_H_ */
