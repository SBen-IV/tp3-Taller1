#include "GestorDeClientes.h"

#define VACIO ""

GestorDeClientes::GestorDeClientes(const char* puerto,
									const char* _archivo_raiz) :
									socket(NULL, puerto, AI_PASSIVE),
									archivo_raiz(_archivo_raiz) {
	this->socket.enlazar();
}

void GestorDeClientes::operator()() {
	this->socket.conectarConCliente();

	char buffer[TAM_BUFFER] = VACIO;
	int bytes_recibidos = 0;
//	Buffer todo lo recibido
	std::string recibido;

	do {
		//TODO:
		bytes_recibidos = this->socket.recibir(buffer, TAM_BUFFER);
		recibido += buffer;
	} while (bytes_recibidos > 0);

	this->socket.enviar(recibido.c_str(), 10);
}



GestorDeClientes::~GestorDeClientes() {}
