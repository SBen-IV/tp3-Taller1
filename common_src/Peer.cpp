#include "Peer.h"
#include <utility>

#define ERROR -1

#define SOCKET_CERRADO 0

Peer::Peer(const int _peer) : peer(_peer) {}

int Peer::enviar(const char* buffer, int cant_bytes) {
	int total_bytes_enviados = 0;
	bool esta_abierto = true;

	while (total_bytes_enviados < cant_bytes && esta_abierto) {
		int bytes_enviados = send(this->peer,
								&buffer[total_bytes_enviados],
								cant_bytes - total_bytes_enviados,
								MSG_NOSIGNAL);
		if (bytes_enviados == ERROR) {
			esta_abierto = false;
		} else if (bytes_enviados == SOCKET_CERRADO) {
			esta_abierto = false;
		} else {
			total_bytes_enviados += bytes_enviados;
		}
	}

	return total_bytes_enviados;
}

int Peer::recibir(char* buffer, int cant_bytes) {
	int total_bytes_recibidos = 0;
	bool esta_abierto = true;

	while (total_bytes_recibidos < cant_bytes && esta_abierto) {
		int bytes_enviados = recv(this->peer,
								&buffer[total_bytes_recibidos],
								cant_bytes - total_bytes_recibidos,
								MSG_NOSIGNAL);
		if (bytes_enviados == ERROR) {
			esta_abierto = false;
		} else if (bytes_enviados == SOCKET_CERRADO) {
			esta_abierto = false;
		} else {
			total_bytes_recibidos += bytes_enviados;
		}
	}

	return total_bytes_recibidos;
}

Peer::Peer(Peer&& otro) {
	this->peer = std::move(otro.peer);
}

Peer& Peer::operator=(Peer&& otro) {
	this->peer = std::move(otro.peer);

	return *this;
}

void Peer::pararEnvio() {
	if (this->peer != -1) shutdown(this->peer, SHUT_WR);
}

void Peer::parar() {
	if (this->peer != -1) shutdown(this->peer, SHUT_RDWR);
}

void Peer::cerrar() {
	if (this->peer != -1) close(this->peer);
}

Peer::~Peer() {}