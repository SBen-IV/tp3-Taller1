#include "RecursosProtected.h"

RecursosProtected::RecursosProtected(const char* _archivo_raiz) :
									recursos(_archivo_raiz) {}

std::string RecursosProtected::obtenerRespuesta(const std::string& metodo,
											const std::string& recurso,
											const std::string& contenido) {
	std::lock_guard<std::mutex> lock(this->m);
	return this->recursos.obtenerRespuesta(metodo, recurso, contenido);
}

RecursosProtected::~RecursosProtected() {}
