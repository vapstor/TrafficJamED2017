/*
 * listaPistas.h
 *
 *  Created on: 24 de set de 2017
 *      Author: vapstor
 */

#ifndef PISTAS_LISTAPISTAS_H_
#define PISTAS_LISTAPISTAS_H_

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./Estruturas/linked_list.h" //! Fila Encadeada
//#include "./Estruturas/linked_queue.h" //! Fila Encadeada
#include "Pista.h";
#include "PistaFonte.h"
#include "PistaSumidouro.h"

namespace structures {

template<typename T>
	//! Classe Lista Pistas (Lista Encadeada)
	class listaPistas : public LinkedList<T>, public PistaSumidouro<T>, public PistaFonte<T>{

		listaPistas() {
			//! Cria Lista
			LinkedList<T>::head = NULL;
			LinkedList<T>::size_ = 0;

			//! Instancia Pistas Sumidouro (Esquerda)
			O1oeste = new PistaSumidouro(22.22222, 2000); //! 22,22 m/s ~80km/h
			N1norte = new PistaSumidouro(16.66666, 500); //! 16,66 m/s ~60km/h
			S1sul = new PistaSumidouro(16.66666, 500); //! 16,66 m/s ~60km/h

			//! Instancia Pistas Sumidouro (Direita)
			N2norte = new PistaSumidouro(11.11111, 500); //! 11,11 m/s ~40km/h
			S2sul = new PistaSumidouro(11.11111, 500); //! 11,11 m/s ~40km/h
			L1leste = new PistaSumidouro(8.33333, 400); //! 8,33 m/s ~30km/h

			//! Instancia Pistas Fontes (Esquerda)
			O1leste = new PistaFonte(22.22222, 2000, f);  //! 22,22 m/s ~80km/h
			N1sul = new PistaFonte(16.66666, 500, f); //! 16,66 m/s ~60km/h
			S1norte = new PistaFonte(16.66666, 500, f); //! 16,66 m/s ~60km/h

			//! Instancia Pistas Fontes (Direita)
			N2sul = new PistaFonte(11.11111, 500, f); //! 11,11 m/s ~40km/h
			S2norte = new PistaFonte(11.11111, 500, f); //! 11,11 m/s ~40km/h
			L1oeste = new PistaFonte(8.33333, 400, f);//! 8,33 m/s ~30km/h

			//! Instancia Pistas Centrais
			C1oeste = new Pista(16,66666, 300); //! 16,66 m/s ~60km/h
			C1leste = new Pista(16,66666, 300); //! 16,66 m/s ~60km/h

			AdicionaPistasNaLista(); //! Adiciona as Pistas à Lista de Pistas
		}

		void AdicionaPistasNaLista() {
			//! Adiciona Pistas Sumidouro à Lista de Pistas
			LinkedList<T>::push_back(O1oeste);
			LinkedList<T>::push_back(N1norte);
			LinkedList<T>::push_back(S1sul);
			LinkedList<T>::push_back(N2norte);
			LinkedList<T>::push_back(S2sul);
			LinkedList<T>::push_back(L1leste);

			//! Adiciona Pistas Fontes à Lista de Pistas
			LinkedList<T>::push_back(O1oeste);
			LinkedList<T>::push_back(N1norte);
			LinkedList<T>::push_back(S1sul);
			LinkedList<T>::push_back(N2norte);
			LinkedList<T>::push_back(S2sul);
			LinkedList<T>::push_back(L1leste);

			//! Adiciona Pistas Centrais à Lista de Pistas
			LinkedList<T>::push_back(C1oeste);
			LinkedList<T>::push_back(C1leste);
		}

		~listaPistas() {
			LinkedList<T>::clear();
		}
	};

	//! Declaração das Pistas

	PistaSumidouro O1oeste, N1norte, S1sul; //! Pistas Sumidouros lado Esquerdo
	PistaSumidouro N2norte, S2sul, L1leste; //! Pistas Sumidouros lado Direito

	PistaFonte O1leste, N1sul, S1norte; //!Pistas Fontes lado Esquerdo
	PistaFonte N2sul, S2norte, L1oeste; //! Pistas Fontes lado Direito

	Pista C1oeste, C1leste; //! Pistas Centrais
}



#endif /* PISTAS_LISTAPISTAS_H_ */
