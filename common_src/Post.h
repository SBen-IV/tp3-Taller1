#ifndef POST_H
#define POST_H

#include "TipoMetodo.h"
#include <string>

class Post : public TipoMetodo {
public:
	Post();
	std::string obtener(Hash& recursos, const std::string& recurso,
						const std::string& contenido) override;
	~Post();
};

#endif
