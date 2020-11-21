#ifndef TIPOMETODO_H
#define TIPOMETODO_H

#include <map>
#include <string>

//TipoMetodo es una clase abstracta, no tiene definición de los métodos.

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
