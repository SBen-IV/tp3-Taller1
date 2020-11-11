#include "GetRaiz.h"
#include <string>

const char RESPUESTA_DEFAULT[] = "HTTP/1.1 200 OK\n"
								"Content-Type: text/html\n\n";

GetRaiz::GetRaiz() {}

std::string GetRaiz::obtener(Hash& recursos, const std::string& recurso,
							const std::string& contenido) {
	std::string respuesta = RESPUESTA_DEFAULT;

	respuesta += recursos[recurso];

	return respuesta;
}

GetRaiz::~GetRaiz() {}
