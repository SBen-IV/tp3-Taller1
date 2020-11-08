#include "Comunicador.h"

#include <iostream>
#include <sstream>

#define VACIO ""

Comunicador::Comunicador(const char* ip, const char* puerto) : 
							socket(ip, puerto, 0) {}

void Comunicador::conectar() {
	this->socket.conectar();
}

void Comunicador::iniciarCliente() {
	char buffer[TAM_BUFFER] = VACIO;
	int enviados = 0;

	do {
		int leidos = fread(buffer, 1, TAM_BUFFER, stdin);
	/*	TODO:
		std::cin.getline(buffer, TAM_BUFFER);
		leidos = std::cin.gcount();*/
		enviados = this->socket.enviar(buffer, leidos);
	} while (enviados > 0);


	std::string recibido;
	int bytes_recibidos = 0;

	do {
		try {
			bytes_recibidos = this->socket.recibir(buffer, TAM_BUFFER);
		} catch (const ErrorSocket& e) {
			bytes_recibidos = -1;
		}
		recibido += buffer;
	} while (bytes_recibidos > 0);

	std::cout << recibido << std::endl;
}

Comunicador::~Comunicador() {}