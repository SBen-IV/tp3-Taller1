#ifndef POSTRAIZ_H
#define POSTRAIZ_H

#include "TipoMetodo.h"

#include <string>

//PostRaiz es un TipoMetodo que devuelve un mensaje de error siempre
//dado que no es posible cambiar el contenido de la raiz.

class PostRaiz : public TipoMetodo {
public:
	PostRaiz();
	std::string obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) override;
	~PostRaiz();
};

#endif
