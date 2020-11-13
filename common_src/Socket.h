#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <string>

#include "ErrorConectar.h"
#include "ErrorSocket.h"
#include "Peer.h"

#define TAM_BUFFER 64

class Socket {
private:
	struct addrinfo* resultado;
	int file_descriptor;
public:
	Socket(const char* ip, const char* puerto, int flag);
	Socket(const Socket& otro) = delete;
	Socket& operator=(const Socket& otro) = delete;
	Peer conectar();
	void enlazar();
	void escuchar();
	Peer aceptarCliente();
	int enviar(const char buffer[TAM_BUFFER], int cant_bytes);
	int recibir(char* buffer, int cant_bytes);
	void parar();
	~Socket() noexcept;
};

#endif
