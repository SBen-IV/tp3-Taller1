#include "Otro.h"
#include <string>

const char MENSAJE_DEFAULT[] = "HTTP/1.1 405 METHOD NOT ALLOWED\n\n";
const char CMD_DESCONOCIDO[] = " es un comando desconocido\n";

Otro::Otro() {}

std::string Otro::obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) {
	std::string respuesta = MENSAJE_DEFAULT + metodo + CMD_DESCONOCIDO;

	return respuesta;
}


Otro::~Otro() {}
