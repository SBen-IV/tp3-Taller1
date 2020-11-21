#ifndef OTRO_H
#define OTRO_H

#include "TipoMetodo.h"
#include <string>

//Otro es un TipoMetodo que devuelve siempre el método más un mensaje
//predeterminado de método desconocido.

class Otro : public TipoMetodo {
public:
	Otro();
	std::string obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) override;
	~Otro();
};

#endif
