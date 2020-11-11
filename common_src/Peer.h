#ifndef PEER_H
#define PEER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>

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
	int enviar(const char* buffer, int cant_bytes);
	int recibir(char* buffer, int cant_bytes);
	void pararEnvio();
	void parar();
	void cerrar();
	~Peer();
};

#endif
