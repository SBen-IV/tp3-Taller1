#ifndef GET_H
#define GET_H

#include "TipoMetodo.h"
#include <string>

class Get : public TipoMetodo {
public:
	Get();
	std::string obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) override;
	~Get();
};

#endif
