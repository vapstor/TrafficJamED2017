/*
 * gerador.h
 *
 *  Created on: 25 de set de 2017
 *      Author: vapstor
 */

#ifndef GERADORVALORESALEATORIO_GERADOR_H_
#define GERADORVALORESALEATORIO_GERADOR_H_

#include <stdlib.h>

namespace structures {

template<typename T>
	class Gerador {
	public:
		Gerador(int lI, int lS) {
			limiteInferior = lI;
			limiteSuperior = lS;
		}

		int NumeroAleatorio() {
			srand((unsigned)time(NULL)); //numero aleatorio
			return int(((double(rand())/RAND_MAX)*(limiteSuperior - limiteInferior)) +limiteInferior);
		}

	public:
		int limiteInferior, limiteSuperior;
	};
}

#endif /* GERADORVALORESALEATORIO_GERADOR_H_ */
