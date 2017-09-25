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
#include "./geradorValoresAleatorio/Gerador.h"

namespace structures {

template <typename carros>
	class PistaFonte : Pista<carros>{
		public:
			PistaFonte(double v, int t, int li, int ls) {
				velocidadePista = v;
				tamanho = t;
				varianciaFonte = calculaVariancia(li, ls);
			}

			int calculaVariancia(int limiteInferior, int limiteSuperior) {
				return Gerador<T>::numAleatorio(limiteInferior, limiteSuperior);
			}

		protected:
			double velocidadePista;
			int tamanho;
			int varianciaFonte;

	};
}


#endif /* PISTAS_PISTAFONTE_H_ */
