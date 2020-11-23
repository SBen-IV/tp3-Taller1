#include "Recursos.h"
#include "Archivo.h"
#include "GetRaiz.h"
#include "Get.h"
#include "PostRaiz.h"
#include "Post.h"
#include "Otro.h"

#include <utility>

#define ARCHIVO_RAIZ "/"
#define GET "GET"
#define POST "POST"

Recursos::Recursos(const char* _archivo_raiz) {
	Archivo archivo(_archivo_raiz);
	std::string linea, contenido;

	while (!archivo.esEOF()) {
		archivo.leer(linea);
		contenido += linea;
	}

	this->recursos[ARCHIVO_RAIZ] = std::move(contenido);
}

std::string Recursos::obtenerRespuesta(const std::string& metodo,
										const std::string& recurso,
										const std::string& contenido) {
	std::string respuesta;
	TipoMetodo* tipo_metodo;

	if (metodo == GET) {
		if (recurso == ARCHIVO_RAIZ){
			tipo_metodo = new GetRaiz();
		} else {
			tipo_metodo = new Get();
		}
	} else if (metodo == POST) {
		if (recurso == ARCHIVO_RAIZ) {
			tipo_metodo = new PostRaiz();
		} else {
			tipo_metodo = new Post();
		}
	} else {
		tipo_metodo = new Otro();
	}

	respuesta = tipo_metodo->obtener(this->recursos, metodo, recurso,
									contenido);

	delete tipo_metodo;

	return respuesta;
}

Recursos::~Recursos() {}
