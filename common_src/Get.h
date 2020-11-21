#ifndef GET_H
#define GET_H

#include "TipoMetodo.h"
#include <string>

//Get es un TipoMetodo que devuelve el contenido que está dentro de recursos
//con la clave recurso. Si el recurso no existe, devuelve un mensaje de error.

class Get : public TipoMetodo {
public:
	Get();
	std::string obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) override;
	~Get();
};

#endif
