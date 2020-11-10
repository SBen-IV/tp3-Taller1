#include "ThCliente.h"
#include <iostream>
#include <string>

#define VACIO ""
#define TAM_BUFFER 5

ThCliente::ThCliente(Peer& _peer, Recursos& _recursos) :
										mantener_conexion(true),
										esta_conectado(true),
										recursos(_recursos),
										peer(std::move(_peer)) {}

void ThCliente::run() {
	char buffer[TAM_BUFFER] = VACIO;
	std::string mensaje_completo;
	int leidos = 0;

	do {
		leidos = this->peer.recibir(buffer, TAM_BUFFER);
		mensaje_completo.append(buffer, leidos);
	} while (leidos > 0);

	Parser parser(mensaje_completo);

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
}

void ThCliente::stop() {
	this->mantener_conexion = false;
	this->peer.parar();
	this->peer.cerrar();
}

ThCliente::~ThCliente() {}
