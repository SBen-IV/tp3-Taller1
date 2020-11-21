#ifndef PEER_H
#define PEER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>

//Peer tiene un peer pasado por el Socket. Se encarga de enviar y recibir
//mensajes que se manden entre el servidor y el cliente.

class Peer {
private:
	int peer;
public:
	explicit Peer(const int _peer);
	Peer(const Peer& otro) = delete;
	Peer& operator=(const Peer& otro) = delete;
	Peer(Peer&& otro);
	Peer& operator=(Peer&& otro);
	Peer& operator=(int otro);
	int enviar(const char* buffer, int cant_bytes) const;
	int recibir(char* buffer, int cant_bytes) const;
	void pararEnvio() const;
	void parar() const;
	void cerrar();
	~Peer();
};

#endif
