#include "GestorDeClientes.h"
#include "ThCliente.h"
#include <vector>
#include <iostream>

#define VACIO ""
#define SUCCESS 0

GestorDeClientes::GestorDeClientes(const char* puerto,
									const char* _archivo_raiz) :
									socket(NULL, puerto, AI_PASSIVE),
									recursos(_archivo_raiz),
									esta_conectado(true) {
	this->socket.enlazar();
}

void GestorDeClientes::terminarClientes(const std::vector<ThCliente*>&
										clientes) {
	for (auto cliente : clientes) {
		cliente->stop();
		cliente->join();
		delete cliente;
	}
}

void GestorDeClientes::limpiarClientes(std::vector<ThCliente*>& clientes) {
	std::size_t largo_clientes = clientes.size();
	std::vector<ThCliente*> clientes_aux;

	for(size_t i = 0; i < largo_clientes; ++i) {
		if (clientes[i]->termino()) {
			clientes[i]->join();
			delete clientes[i];
		} else {
			clientes_aux.push_back(clientes[i]);
		}
	}

	clientes.swap(clientes_aux);
}

void GestorDeClientes::operator()() {
	std::vector<ThCliente*> clientes;

	while (this->esta_conectado) {
		if (this->socket.hayClientes() == SUCCESS){
			Peer peer = this->socket.aceptarCliente();

			clientes.push_back(new ThCliente(peer, recursos));
			clientes.back()->start();
			GestorDeClientes::limpiarClientes(clientes);
		}
	}

	GestorDeClientes::terminarClientes(clientes);
}

void GestorDeClientes::finalizar() {
	this->esta_conectado = false;
	this->socket.parar();
}

GestorDeClientes::~GestorDeClientes() {}
