#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "GestorDeClientes.h"

class Servidor {
private:
	GestorDeClientes gestor;
public:
	Servidor(const char* puerto, const char* archivo_raiz);
	void operator()();
	~Servidor();
};

#endif
