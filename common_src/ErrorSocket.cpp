#include "ErrorSocket.h"

ErrorSocket::ErrorSocket() noexcept {
	int _errno = errno;

	memcpy(this->msj_error, strerror(_errno), strlen(strerror(_errno)) + 1);
}

const char* ErrorSocket::what() const noexcept {
	return this->msj_error;
}

ErrorSocket::~ErrorSocket() {}
