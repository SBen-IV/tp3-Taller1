#ifndef POSTRAIZ_H
#define POSTRAIZ_H

#include "TipoMetodo.h"

#include <string>

class PostRaiz : public TipoMetodo {
public:
	PostRaiz();
	std::string obtener(Hash& recursos, const std::string& recurso,
						const std::string& contenido) override;
	~PostRaiz();
};

#endif
