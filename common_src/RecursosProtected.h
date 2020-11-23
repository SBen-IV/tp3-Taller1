#ifndef RECURSOSPROTECTED_H
#define RECURSOSPROTECTED_H

#include <mutex>
#include <string>

#include "Recursos.h"

class RecursosProtected {
private:
	Recursos recursos;
	std::mutex m;
public:
	explicit RecursosProtected(const char* _archivo_raiz);
	std::string obtenerRespuesta(const std::string& metodo,
								const std::string& recurso,
								const std::string& contenido);
	~RecursosProtected();
};

#endif
