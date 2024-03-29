#include "Socket.h"

#define SUCCESS 0
#define ERROR -1

#define SOCKET_CERRADO 0
#define PEER_ERROR -1
#define FD_ERROR -1
#define MAX_CLIENTES 10

Socket::Socket(const char* ip, const char* puerto, int flag) :
				file_descriptor(FD_ERROR) {
	struct addrinfo hints;

	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = flag;

	int estado = getaddrinfo(ip, puerto, &hints, &(this->resultado));

	if (estado != SUCCESS) {
		freeaddrinfo(this->resultado);
		throw ErrorSocket("No se pudo inicializar el socket.");
	}
}

Peer Socket::conectar() {
	struct addrinfo* resultado_aux = this->resultado;

	while (resultado_aux) {
		int _peer = socket(resultado_aux->ai_family,
										resultado_aux->ai_socktype,
										resultado_aux->ai_protocol);

		if (_peer != PEER_ERROR) {
			if (connect(_peer, resultado_aux->ai_addr,
						resultado_aux->ai_addrlen) == SUCCESS) {
				return Peer(_peer);
			} else {
				close(_peer);
			}
		}

		resultado_aux = resultado_aux->ai_next;
	}

	throw ErrorConectar("No se pudo conectar con el"
						" servidor.");
}

void Socket::enlazar() {
	bool esta_conectado = false;
	struct addrinfo* resultado_aux = this->resultado;

	while (resultado_aux && !esta_conectado) {
		this->file_descriptor = socket(resultado_aux->ai_family,
										resultado_aux->ai_socktype,
										resultado_aux->ai_protocol);

		int opcion = 1;
		setsockopt(this->file_descriptor, SOL_SOCKET, SO_REUSEADDR,
					&opcion, sizeof(opcion));

		if (this->file_descriptor != FD_ERROR) {
			if (bind(this->file_descriptor, resultado_aux->ai_addr,
						resultado_aux->ai_addrlen) == SUCCESS) {
				esta_conectado = true;
			} else {
				close(this->file_descriptor);
			}
		}

		resultado_aux = resultado_aux->ai_next;
	}

	if (!esta_conectado) throw ErrorConectar("No se pudo enlazar con el"
											" servidor.");
}


void Socket::escuchar() {
	listen(this->file_descriptor, MAX_CLIENTES);
}

Peer Socket::aceptarCliente() {
	Peer peer(accept(this->file_descriptor, NULL, NULL));
	
	return peer;
}

void Socket::parar() {
	if (this->file_descriptor != FD_ERROR) {
		shutdown(this->file_descriptor, SHUT_RDWR);
	}
}

Socket::~Socket() noexcept {
	if (this->file_descriptor != FD_ERROR) {
		shutdown(this->file_descriptor, SHUT_RDWR);
		close(this->file_descriptor);
	}
	
	freeaddrinfo(this->resultado);
}
