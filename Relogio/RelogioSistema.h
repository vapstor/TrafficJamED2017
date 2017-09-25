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

namespace structures {

template <typename T>

class RelogioSistema : LinkedList<T>, ListaSemaforos<T>, Carro<T>{
	public:
		RelogioSistema() {

		}



		inserirCarro() {
			inserir
		}

		mudancaEstadoSemaforo();

		carroNoSemaforo() {
			if (pode cruzar)

		}

		void trocaPista() {

		}

	protected:
	};
}


#endif /* RELOGIO_RELOGIOSISTEMA_H_ */
