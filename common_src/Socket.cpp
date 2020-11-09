#include "Socket.h"

#define SUCCESS 0
#define ERROR -1

#define SOCKET_CERRADO 0
#define PEER_ERROR -1
#define FD_ERROR -1
#define MAX_CLIENTES 5

Socket::Socket(const char* ip, const char* puerto, int flag) :
				file_descriptor(FD_ERROR), peer(PEER_ERROR) {
	struct addrinfo hints;

	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = flag;

	int estado = getaddrinfo(ip, puerto, &hints, &(this->resultado));

	if (estado != SUCCESS) {
		freeaddrinfo(this->resultado);
		throw -1; //TODO: Cambiar excepcion.
	}
}

void Socket::conectar() {
	bool esta_conectado = false;
	struct addrinfo* resultado_aux = this->resultado;

	while (resultado_aux && !esta_conectado) {
		this->peer = socket(resultado_aux->ai_family,
										resultado_aux->ai_socktype,
										resultado_aux->ai_protocol);

		if (this->peer != PEER_ERROR) {
			if (connect(this->peer, resultado_aux->ai_addr,
						resultado_aux->ai_addrlen) == SUCCESS) {
				esta_conectado = true;
			} else {
				close(this->peer);
			}
		}

		resultado_aux = resultado_aux->ai_next;
	}

	if (!esta_conectado) throw ErrorConectar("No se pudo conectar con el"
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


int Socket::hayClientes() {
	return listen(this->file_descriptor, MAX_CLIENTES);
}

Peer Socket::aceptarCliente() {
	Peer peer(accept(this->file_descriptor, NULL, NULL));
	
	return peer;
}

int Socket::enviar(const char* buffer, int cant_bytes) {
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

int Socket::recibir(char* buffer, int cant_bytes) {
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

Socket::~Socket() noexcept {
	if (this->peer != PEER_ERROR) {
		shutdown(this->peer, SHUT_RDWR);
		close(this->peer);	
	}

	if (this->file_descriptor != FD_ERROR) {
		shutdown(this->file_descriptor, SHUT_RDWR);
		close(this->file_descriptor);
	}
	
	freeaddrinfo(this->resultado);
}
