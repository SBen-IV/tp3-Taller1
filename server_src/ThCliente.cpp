#include "ThCliente.h"
#include <iostream>
#include <string>

#define VACIO ""
#define TAM_BUFFER 5

ThCliente::ThCliente(Peer& _peer) : mantener_conexion(true),
										esta_conectado(true),
										peer(std::move(_peer)) {
}

void ThCliente::run() {
	char buffer[TAM_BUFFER] = VACIO;
	std::string mensaje_completo;
	int leidos = 0;

	do {
		leidos = this->peer.recibir(buffer, TAM_BUFFER);
		mensaje_completo.append(buffer, leidos);
	} while (leidos > 0);

	mensaje_completo.push_back('\0');

	Parser parser(mensaje_completo);

	std::string metodo = parser.obtenerPalabra();
	std::string recurso = parser.obtenerPalabra();
	std::string protocolo = parser.obtenerPalabra();

	std::cout << metodo << ' ' << recurso << ' ' << protocolo << std::endl;

	std::string contenido = parser.obtenerContenido();

	std::cout << contenido << std::endl;
/*
	recibir
	parsear
	enviar
*/
}

void ThCliente::stop() {
	this->mantener_conexion = false;
	this->peer.parar();
	this->peer.cerrar();
}

ThCliente::~ThCliente() {}
