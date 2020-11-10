#ifndef RECURSOS_H
#define RECURSOS_H

#include <map>
#include <string>

#include "TipoMetodo.h"

class Recursos {
private:
	std::map<std::string, std::string> recursos;
public:
	Recursos(const char* _archivo_raiz);
	std::string obtenerRespuesta(const std::string& metodo,
									const std::string& recurso,
									const std::string& contenido);
	~Recursos();
};

#endif
