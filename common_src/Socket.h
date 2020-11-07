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

class Socket {
private:
	struct addrinfo* resultado;
	int file_descriptor;
	int peer;
public:
	Socket(const char* ip, const char* puerto, int flag);
	Socket(const Socket& otro) = delete;
	Socket& operator=(const Socket& otro) = delete;
	void conectar();
	int enviar(char* buffer, int cant_bytes);
	~Socket() noexcept;
};

#endif
