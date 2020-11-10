#include "Recursos.h"
#include "Archivo.h"
#include "GetRaiz.h"
#include "Get.h"
#include "PostRaiz.h"
#include "Post.h"
#include "Otro.h"

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
	Otro otro;
	tipo_metodo = &otro;

	if (metodo == GET) {
		if (recurso == ARCHIVO_RAIZ){
			GetRaiz get_raiz;
			tipo_metodo = &get_raiz;
		} else {
			Get get;
			tipo_metodo = &get;
		}
	} else if (metodo == POST) {
		if (recurso == ARCHIVO_RAIZ) {
			PostRaiz post_raiz;
			tipo_metodo = &post_raiz;
		} else {
			Post post;
			tipo_metodo = &post;
		}
	}

	respuesta = tipo_metodo->obtener(this->recursos, recurso, contenido);

	return respuesta;
}

Recursos::~Recursos() {}