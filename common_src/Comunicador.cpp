#include "Comunicador.h"

#include <iostream>

#define TAM_BUFFER 3
#define VACIO ""

Comunicador::Comunicador(const char* ip, const char* puerto) : 
							socket(ip, puerto, 0) {
}

void Comunicador::conectar() {
	try {
		this->socket.conectar();
	} catch (ErrorConectar& e) {
		printf("%s\n", e.what());
	}
}

void Comunicador::iniciarCliente() {
	char buffer[TAM_BUFFER] = VACIO;
	int leidos = 0, enviados = 0;

	do {
		std::cin.getline(buffer, TAM_BUFFER);
		leidos = std::cin.gcount();
		enviados = this->socket.enviar(buffer, leidos);
	} while (enviados > 0);
}

Comunicador::~Comunicador() {}