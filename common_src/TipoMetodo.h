#ifndef TIPOMETODO_H
#define TIPOMETODO_H

#include <map>
#include <string>

typedef std::map<std::string, std::string> Hash;

class TipoMetodo {
public:
	TipoMetodo();
	virtual std::string obtener(Hash& recursos,
								const std::string& metodo,
								const std::string& recurso,
								const std::string& contenido) = 0;
	virtual ~TipoMetodo();
};

#endif
