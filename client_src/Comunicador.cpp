#include "Comunicador.h"

#include <iostream>
#include <sstream>
#include <string>

#define VACIO ""

Comunicador::Comunicador(const char* ip, const char* puerto) : 
							socket(ip, puerto, 0) {}

void Comunicador::leerEntradaEstandar(std::string& mensaje) {
	char buffer[TAM_BUFFER] = VACIO;
	int leidos = 0;

	do {
		leidos = fread(buffer, 1, TAM_BUFFER, stdin);
		mensaje.append(buffer, leidos);
	} while (leidos > 0);
}

void Comunicador::recibirRespuesta(std::string& respuesta, const Peer& peer) {
	char buffer[TAM_BUFFER] = VACIO;
	int bytes_recibidos = 0;

	do {
		bytes_recibidos = peer.recibir(buffer, TAM_BUFFER);
		respuesta.append(buffer, bytes_recibidos);
	} while (bytes_recibidos == TAM_BUFFER);
}

void Comunicador::operator()() {
	Peer peer(this->socket.conectar());
	std::string mensaje;

	Comunicador::leerEntradaEstandar(mensaje);

	peer.enviar(mensaje.c_str(), mensaje.length());

	peer.pararEnvio();

	std::string respuesta;

	Comunicador::recibirRespuesta(respuesta, peer);

	std::cout << respuesta;
}

Comunicador::~Comunicador() {}
