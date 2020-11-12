#include "Get.h"
#include <stdexcept>
#include <string>

const char MENSAJE_OK[] = "HTTP/1.1 200 OK\n\n";
const char MENSAJE_ERROR[] = "HTTP/1.1 404 NOT FOUND\n\n";

Get::Get() {}

std::string Get::obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) {
	std::string respuesta = MENSAJE_OK;
	try {
		std::string aux = recursos.at(recurso);
		respuesta += aux;
	} catch (const std::out_of_range& e) {
		respuesta = MENSAJE_ERROR;
	}

	return respuesta;
}

Get::~Get() {}
