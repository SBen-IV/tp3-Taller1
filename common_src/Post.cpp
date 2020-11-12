#include "Post.h"

#include <string>

const char MENSAJE_DEFAULT[] = "HTTP/1.1 200 OK\n\n";

Post::Post() {}

std::string Post::obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) {
	std::string respuesta = MENSAJE_DEFAULT;

	recursos[recurso] = contenido;

	respuesta += contenido;

	return respuesta;
}

Post::~Post() {}
