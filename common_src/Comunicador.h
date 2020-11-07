#ifndef COMUNICADOR_H
#define COMUNICADOR_H

#include <cstring>

#include "Socket.h"

class Comunicador {
private:
	Socket socket;
public:
	Comunicador(const char* puerto);
	Comunicador(const char* ip, const char* puerto);
	void conectar();
	void iniciarCliente();
	~Comunicador();
};

#endif
