#include "GestorDeClientes.h"
#include "ThCliente.h"
#include <vector>
#include <iostream>

#define VACIO ""
#define SUCCESS 0

GestorDeClientes::GestorDeClientes(const char* puerto,
									const char* _archivo_raiz) :
									socket(NULL, puerto, AI_PASSIVE),
									recursos(_archivo_raiz) {
	this->socket.enlazar();
}

void limpiar_clientes(std::vector<Thread*>& clientes) {
	std::cout << "Limpiando clientes" << std::endl;
}

void GestorDeClientes::operator()() {
	std::vector<Thread*> clientes;

	if (this->socket.hayClientes() == SUCCESS) {
		Peer peer = this->socket.aceptarCliente();
			
		clientes.push_back(new ThCliente(peer, recursos));
		clientes.back()->start();
		limpiar_clientes(clientes);
		clientes[0]->join();
		delete clientes[0];
	}

/*
	while (this->socket.hayClientes() == SUCCESS) {
		Peer peer = this->socket.aceptarCliente();
		
		clientes.push_back(new ThCliente(peer));

		limpiar_clientes(clientes);

		//Si el socket se cerro hay que terminar
	}*/
}



GestorDeClientes::~GestorDeClientes() {}
