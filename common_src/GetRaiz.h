#ifndef GETRAIZ_H
#define GETRAIZ_H

#include "TipoMetodo.h"
#include <string>

//GetRaiz es un TipoMetodo que devuelve el contenido del recurso
//raiz: '/'.

class GetRaiz : public TipoMetodo {
public:
	GetRaiz();
	std::string obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) override;
	~GetRaiz();
};

#endif
