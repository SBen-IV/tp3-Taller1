#ifndef POST_H
#define POST_H

#include "TipoMetodo.h"
#include <string>

//Post es un TipoMetodo que devuelve un mensaje con el contenido agregado a 
//recursos con la clave recurso. Si el recurso ya existía, se pisa el
//contenido.

class Post : public TipoMetodo {
public:
	Post();
	std::string obtener(Hash& recursos, const std::string& metodo,
						const std::string& recurso,
						const std::string& contenido) override;
	~Post();
};

#endif
