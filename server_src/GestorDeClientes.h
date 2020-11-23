#ifndef GESTORDECLIENTES_H
#define GESTORDECLIENTES_H

#include <string>
#include <vector>
#include <atomic>

#include "ThCliente.h"
#include "../common_src/Socket.h"
#include "../common_src/RecursosProtected.h"

//GestroDeClientes se encarga de ir aceptando e inicializando los clientes
//que van llegando para ser atendidos.

class GestorDeClientes {
private:
	Socket socket;
	RecursosProtected recursos;
	std::atomic<bool> esta_conectado;
public:
	GestorDeClientes(const char* puerto, const char* _archivo_raiz);
	void operator()();
	void finalizar();
	~GestorDeClientes();
private:
	void terminarClientes(const std::vector<ThCliente*>& clientes);
	void limpiarClientes(std::vector<ThCliente*>& clientes);
};

#endif
