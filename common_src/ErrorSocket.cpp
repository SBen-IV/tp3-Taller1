#include "ErrorSocket.h"

ErrorSocket::ErrorSocket() noexcept {
	int _errno = errno;

	memcpy(this->msj_error, strerror(_errno), strlen(strerror(_errno)) + 1);
}
ErrorSocket::ErrorSocket(const char* mensaje) noexcept {
	memcpy(this->msj_error, mensaje, strlen(mensaje) + 1);
}

const char* ErrorSocket::what() const noexcept {
	return this->msj_error;
}

ErrorSocket::~ErrorSocket() {}
