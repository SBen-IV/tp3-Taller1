#include "Socket.h"

#define SUCCESS 0
#define ERROR -1

#define SOCKET_CERRADO 0

Socket::Socket(const char* ip, const char* puerto, int flag) {
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
		this->file_descriptor = socket(resultado_aux->ai_family,
										resultado_aux->ai_socktype,
										resultado_aux->ai_protocol);

		if (this->file_descriptor != ERROR) {
			if (connect(this->file_descriptor, resultado_aux->ai_addr,
						resultado_aux->ai_addrlen) == SUCCESS) {
				esta_conectado = true;
			} else {
				close(this->file_descriptor);
			}
		}

		resultado_aux = resultado_aux->ai_next;
	}

	if (!esta_conectado) throw ErrorConectar("No se pudo conectar con el"
											" servidor.");
}

int Socket::enviar(char* buffer, int cant_bytes) {
	int total_bytes_enviados = 0;

	while (total_bytes_enviados < cant_bytes) {
		int bytes_enviados = send(this->file_descriptor,
								&buffer[total_bytes_enviados],
								cant_bytes - total_bytes_enviados,
								MSG_NOSIGNAL);
		if (bytes_enviados == ERROR) {
			throw ErrorSocket();
		} else if (bytes_enviados == SOCKET_CERRADO) {
			throw ErrorSocket();
		} else {
			total_bytes_enviados += bytes_enviados;
		}
	}

	return total_bytes_enviados;
}

Socket::~Socket() noexcept {
	freeaddrinfo(this->resultado);
}