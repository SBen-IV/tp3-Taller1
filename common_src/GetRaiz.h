#ifndef GETRAIZ_H
#define GETRAIZ_H

#include "TipoMetodo.h"

class GetRaiz : public TipoMetodo {
public:
	GetRaiz();
	std::string obtener(Hash& recursos, const std::string& recurso,
						const std::string& contenido) override;
	~GetRaiz();
};

#endif
