#include "Recursos.h"
#include "Archivo.h"

#define ARCHIVO_RAIZ "/"
#define GET "GET"
#define POST "POST"

Recursos::Recursos(const char* _archivo_raiz) {
	Archivo archivo(_archivo_raiz);
	std::string linea, contenido;

	while (!archivo.esEOF()) {
		archivo.leer(linea);
		contenido.append(linea);
	}

	this->recursos[ARCHIVO_RAIZ] = contenido;
}
/*
TipoMetodo Recursos::obtenerTipoMetodo(const std::string& metodo,
										const std::string& recurso) {
	if (metodo == GET) {
		if (recurso == ARCHIVO_RAIZ){
			return GetRaiz();
		} else {
			return Get();
		}
	} else if (metodo == POST) {
		if (recurso == ARCHIVO_RAIZ) {
			return PostRaiz();
		} else {
			return Post();
		}
	}

	return Otro();
}
*/
/*
std::string Recursos::obtenerRespuesta(TipoMetodo metodo,
										const std::string& recurso) {
	std::string respuesta;

	respuesta = metodo.obtener(recurso);

	return respuesta;
}
*/
std::string Recursos::obtenerRespuesta(const std::string& metodo,
										const std::string& recurso) {
	std::string respuesta;

	if (metodo == GET) {
//		respuesta = this->recursos[recurso]
	} else if (metodo == POST) {

	} else {

	}

	return respuesta;
}

Recursos::~Recursos() {}