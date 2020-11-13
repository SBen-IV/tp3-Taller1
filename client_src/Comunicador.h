#ifndef COMUNICADOR_H
#define COMUNICADOR_H

#include <cstring>
#include <string>

#include "../common_src/Socket.h"

class Comunicador {
private:
	Socket socket;
public:
	Comunicador(const char* ip, const char* puerto);
	void operator()();
	~Comunicador();
private:
	void leerEntradaEstandar(std::string& mensaje);
	void recibirRespuesta(std::string& respuesta, Peer& peer);
};

#endif
