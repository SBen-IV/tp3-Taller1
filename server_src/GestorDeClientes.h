#ifndef GESTORDECLIENTES_H
#define GESTORDECLIENTES_H

#include <string>
#include <vector>
#include <atomic>

#include "ThCliente.h"
#include "../common_src/Socket.h"
#include "../common_src/Recursos.h"

class GestorDeClientes {
private:
	Socket socket;
	Recursos recursos;
	std::atomic<bool> esta_conectado;
public:
	GestorDeClientes(const char* puerto, const char* _archivo_raiz);
	void operator()();
	void finalizar();
	~GestorDeClientes();
private:
	void terminarClientes(std::vector<ThCliente*>& clientes);
	void limpiarClientes(std::vector<ThCliente*>& clientes);
};

#endif
