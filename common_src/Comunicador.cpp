#include "Comunicador.h"

#include <iostream>
#include <sstream>
#include <string>

#define VACIO ""

Comunicador::Comunicador(const char* ip, const char* puerto) : 
							socket(ip, puerto, 0) {}

void Comunicador::conectar() {
	this->socket.conectar();
}

void Comunicador::iniciarCliente() {
	char buffer[TAM_BUFFER] = VACIO;
	int leidos = 0;
	std::string mensaje;

	do {
		/*	TODO:
		std::cin.getline(buffer, TAM_BUFFER);
		leidos = std::cin.gcount();*/
		leidos = fread(buffer, 1, TAM_BUFFER, stdin);
		mensaje.append(buffer, leidos);
	} while (leidos > 0);

	this->socket.enviar(mensaje.c_str(), mensaje.length());

	this->socket.pararEnvio();

	std::string recibido;
	int bytes_recibidos = 0;

	do {
		try {
			bytes_recibidos = this->socket.recibir(buffer, TAM_BUFFER);
			recibido.append(buffer, bytes_recibidos);
		} catch (const ErrorSocket& e) {
			bytes_recibidos = -1;
		}
	} while (bytes_recibidos > 0);

	std::cout << recibido;
}

Comunicador::~Comunicador() {}
