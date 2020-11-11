#include "ErrorConectar.h"

ErrorConectar::ErrorConectar(const char* mensaje) noexcept {
	memcpy(this->msj_error, mensaje, strlen(mensaje) + 1);
}

const char* ErrorConectar::what() const noexcept {
	return this->msj_error;
}

ErrorConectar::~ErrorConectar() {}
