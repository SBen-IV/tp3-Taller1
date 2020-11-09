#ifndef GESTORDECLIENTES_H
#define GESTORDECLIENTES_H

#include <string>

#include "../common_src/Socket.h"
#include "../common_src/Recursos.h"

class GestorDeClientes {
private:
	Socket socket;
	Recursos recursos;
public:
	GestorDeClientes(const char* puerto, const char* _archivo_raiz);
	void operator()();
	~GestorDeClientes();
};

#endif
