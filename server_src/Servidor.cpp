#include "Servidor.h"

#include <iostream>

#define ESPACIO ' '
#define CARACTER_CORTE 'q'

Servidor::Servidor(const char* puerto, const char* archivo_raiz) :
					gestor(puerto, archivo_raiz) {}

void Servidor::operator()() {
//	Lanzo primer hilo
//  thread(GestorDeClientes(puerto, archivo_raiz));
/*
	char c = ESPACIO;

	while (c != CARACTER_CORTE) {
		std::cin.get(c);		
	}
*/
	this->gestor();
//	gestor.finalizar(); // close(socket)
//	join
}

Servidor::~Servidor() {}
