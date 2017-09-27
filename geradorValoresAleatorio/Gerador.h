/*
 * gerador.h
 *
 *  Created on: 25 de set de 2017
 *      Author: vapstor
 */

#ifndef GERADORVALORESALEATORIO_GERADOR_H_
#define GERADORVALORESALEATORIO_GERADOR_H_
//
#include <stdlib.h>
#include <stdio.h>

namespace structures {

template<typename T>
	class Gerador {
	public:
		int numAleatorio(int limiteInferior, int limiteSuperior) {
			srand((unsigned)time(NULL)); //numero aleatorio
			return int(((double(rand())/RAND_MAX)*(limiteSuperior - limiteInferior)) +limiteInferior);
		}
};

#endif /* GERADORVALORESALEATORIO_GERADOR_H_ */
