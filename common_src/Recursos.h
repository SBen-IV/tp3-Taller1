#ifndef RECURSOS_H
#define RECURSOS_H

#include <map>
#include <string>

#include "TipoMetodo.h"

class Recursos {
private:
	Hash recursos;
public:
	explicit Recursos(const char* _archivo_raiz);
	std::string obtenerRespuesta(const std::string& metodo,
									const std::string& recurso,
									const std::string& contenido);
	~Recursos();
};

#endif
