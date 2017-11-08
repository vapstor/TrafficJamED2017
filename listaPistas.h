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
#include "../Estruturas/linked_list.h" //! Fila Encadeada
//#include "./Estruturas/linked_queue.h" //! Fila Encadeada
#include "Pista.h"
#include "PistaFonte.h"
#include "PistaSumidouro.h"

namespace structures {

template<typename T>
	//! Classe Lista Pistas (Lista Encadeada)
class listaPistas : public ArrayList<T>, Pista<T>, PistaFonte<T>, PistaSumidouro<T>{
	public:
		listaPistas() {
			instanciaPistas(); //! instancia Pistas
			AdicionaPistasNaLista(); //! Adiciona as Pistas à Lista de Pistas
		}


		void instanciaPistas() {
			//! Instancia Pistas Sumidouro (Esquerda)
			O1oeste = new PistaSumidouro<T>(22.22222, 2000); //! 22,22 m/s ~80km/h -- Tempo pra Percorrer: 90s
			N1norte = new PistaSumidouro<T>(16.66666, 500); //! 16,66 m/s ~60km/h -- Tempo pra Percorrer: 30s
			S1sul = new PistaSumidouro<T>(16.66666, 500); //! 16,66 m/s ~60km/h
			//! Instancia Pistas Sumidouro (Direita)
			N2norte = new PistaSumidouro<T>(11.11111, 500); //! 11,11 m/s ~40km/h -- Tempo pra Percorrer: 45s
			S2sul = new PistaSumidouro<T>(11.11111, 500); //! 11,11 m/s ~40km/h -- Tempo pra Percorrer: 45s
			L1leste = new PistaSumidouro<T>(8.33333, 400); //! 8,33 m/s ~30km/h -- Tempo pra Percorrer: 38s

			//! Instancia Pistas Fontes (Esquerda)
			O1leste = new PistaFonte<T>(22.22222, 2000, 8, 12);  //! 22,22 m/s ~80km/h f:10s +- 2 -- Tempo pra Percorrer: 90s
			N1sul = new PistaFonte<T>(16.66666, 500, 15, 25); //! 16,66 m/s ~60km/h f:20s +- 5 -- Tempo pra Percorrer: 30s
			S1norte = new PistaFonte<T>(16.66666, 500, 23, 37); //! 16,66 m/s ~60km/h f:30s +- 7 -- Tempo pra Percorrer: 30s

			//! Instancia Pistas Fontes (Direita)
			N2sul = new PistaFonte<T>(11.11111, 500, 15, 25); //! 11,11 m/s ~40km/h f:20s +- 5 -- Tempo pra Percorrer: 45s
			S2norte = new PistaFonte<T>(11.11111, 500, 45, 75); //! 11,11 m/s ~40km/h f: 60s +- 15 -- Tempo pra Percorrer: 45s
			L1oeste = new PistaFonte<T>(8.33333, 400, 8, 12);//! 8,33 m/s ~30km/h f: 10s +- 2 -- Tempo pra Percorrer: 38s

			//! Instancia Pistas Centrais
			C1oeste = new Pista<T>(16,66666, 300); //! 16,66 m/s ~60km/h -- Tempo pra Percorrer: 18s
			C1leste = new Pista<T>(16,66666, 300); //! 16,66 m/s ~60km/h -- Tempo pra Percorrer: 18s
		}

		void AdicionaPistasNaLista() {
			// Array List Pois o tamanho é definido
			// Mais rápido de se chegar nas pistas-fontes (ou outras)

			//! Adiciona Pistas Sumidouro à Lista de Pistas
			/*00*/ listaPistas.push_back(O1oeste);
			/*01*/ listaPistas.push_back(N1norte);
			/*02*/ listaPistas.push_back(S1sul);
			/*03*/ listaPistas.push_back(N2norte);
			/*04*/ listaPistas.push_back(S2sul);
			/*05*/ listaPistas.push_back(L1leste);

			//! Adiciona Pistas Fontes à Lista de Pistas
			/*06*/ listaPistas.push_back(O1oeste);
			/*07*/ listaPistas.push_back(N1norte);
			/*08*/ listaPistas.push_back(S1sul);
			/*09*/ listaPistas.push_back(N2norte);
			/*10*/ listaPistas.push_back(S2sul);
			/*11*/ listaPistas.push_back(L1leste);

			//! Adiciona Pistas Centrais à Lista de Pistas
			/*12*/ listaPistas.push_back(C1oeste);
			/*13*/ listaPistas.push_back(C1leste);
		}

		Pista<T> pistaNoIndice(int index) {
			return listaPistas.at(index);
		}
		//! Declaração das Pistas
	public:
		PistaSumidouro<T> O1oeste, N1norte, S1sul; //! Pistas Sumidouros lado Esquerdo
		PistaSumidouro<T> N2norte, S2sul, L1leste; //! Pistas Sumidouros lado Direito

		PistaFonte<T> O1leste, N1sul, S1norte; //!Pistas Fontes lado Esquerdo
		PistaFonte<T> N2sul, S2norte, L1oeste; //! Pistas Fontes lado Direito

		Pista<T> C1oeste, C1leste; //! Pistas Centrais
		ArrayList<T> listaPistas = new ArrayList<T>[14];
	};


}



#endif /* PISTAS_LISTAPISTAS_H_ */
