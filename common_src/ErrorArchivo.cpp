#include "ErrorArchivo.h"
#include <cstdio>
#include <cstdarg>

ErrorArchivo::ErrorArchivo(const char* formato, ...) noexcept {
	va_list args;
	va_start(args, formato);
	vsnprintf(this->msj_error, MAX_MSJ_ERROR, formato, args);
	va_end(args);
}
const char* ErrorArchivo::what() const noexcept {
	return this->msj_error;
}

ErrorArchivo::~ErrorArchivo() {}