#ifndef OTRO_H
#define OTRO_H

#include "TipoMetodo.h"
#include <string>

class Otro : public TipoMetodo {
public:
	Otro();
	std::string obtener(Hash& recursos, const std::string& recurso,
						const std::string& contenido) override;
	~Otro();
};

#endif
