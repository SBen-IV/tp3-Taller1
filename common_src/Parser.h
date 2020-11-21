#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>

//Parser se encarga de separar el mensaje (obtenerPalabra) con el delimitador
// espacio y separar el contenido desde una línea vacía a otra
// (obtenerContenido).

class Parser {
private:
	std::stringstream mensaje;
public:
	explicit Parser(const std::string& _mensaje);
	std::string obtenerPalabra();
	std::string obtenerContenido();
	~Parser();
};

#endif
