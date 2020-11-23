#ifndef RECURSOSPROTECTED_H
#define RECURSOSPROTECTED_H

#include <mutex>
#include <string>

#include "Recursos.h"

//RecursosProtected protege la clase Recursos al momento de llamar a 
//obtenerRespuesta que es una critical section de Recursos porque es accedido
//por varios threads.

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
