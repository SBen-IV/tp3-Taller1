#include "Otro.h"
#include <string>

const char MENSAJE_DEFAULT[] = "HTTP/1.1 405 METHOD NOT ALLOWED\n\n";

Otro::Otro() {}

std::string Otro::obtener(Hash& recursos, const std::string& recurso,
						const std::string& contenido) {
	std::string respuesta = MENSAJE_DEFAULT;
	return respuesta;
}


Otro::~Otro() {}
