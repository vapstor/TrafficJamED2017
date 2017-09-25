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

namespace structures {

template <typename T>

class RelogioSistema : LinkedList<T>, ListaSemaforos<T>{
	public:
		RelogioSistema() {

		}



		inserirCarro();

		mudancaEstadoSemaforo();

		carroNoSemaforo() {
			if (pode cruzar)

		}

		trocaPista();

	protected:
	};
}


#endif /* RELOGIO_RELOGIOSISTEMA_H_ */
