#include "PostRaiz.h"

#include <string>

const char MENSAJE_ERROR[] = "HTTP/1.1 403 FORBIDDEN\n\n";

PostRaiz::PostRaiz() {}

std::string PostRaiz::obtener(Hash& recursos, const std::string& metodo,
							const std::string& recurso,
							const std::string& contenido) {
	std::string respuesta = MENSAJE_ERROR;

	return respuesta;
}

PostRaiz::~PostRaiz() {}
