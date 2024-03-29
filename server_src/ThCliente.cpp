#include "ThCliente.h"
#include <iostream>
#include <string>
#include <utility>

#define VACIO ""
#define TAM_BUFFER 5

ThCliente::ThCliente(Peer& _peer, RecursosProtected& _recursos) :
					esta_conectado(true), recursos(_recursos),
					peer(std::move(_peer)) {}

void ThCliente::obtenerPetitorio(std::string& petitorio) {
	char buffer[TAM_BUFFER] = VACIO;
	int leidos = 0;

	do {
		leidos = this->peer.recibir(buffer, TAM_BUFFER);
		petitorio.append(buffer, leidos);
	} while (leidos > 0);
}

void ThCliente::run() {
	std::string petitorio;

	ThCliente::obtenerPetitorio(petitorio);

	Parser parser(petitorio);

	std::string metodo = parser.obtenerPalabra();
	std::string recurso = parser.obtenerPalabra();
	std::string protocolo = parser.obtenerPalabra();

	std::cout << metodo << ' ' << recurso << ' ' << protocolo << std::endl;

	std::string contenido = parser.obtenerContenido();

	std::string respuesta = this->recursos.obtenerRespuesta(metodo,
															recurso,
															contenido);

	int largo_respuesta = respuesta.length();

	this->peer.enviar(respuesta.c_str(), largo_respuesta);

	this->peer.parar();

	this->esta_conectado = false;
}

void ThCliente::stop() {
	this->peer.parar();
	this->peer.cerrar();
}

bool ThCliente::termino() {
	return !(this->esta_conectado);
}

ThCliente::~ThCliente() {}
