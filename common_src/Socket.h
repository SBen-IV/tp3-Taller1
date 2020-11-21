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

//Socket es la clase encargada de inicializar, conectar/enlazar y aceptar
//clientes. Funciona tanto para servidor como para cliente.

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
	void parar();
	~Socket() noexcept;
};

#endif
