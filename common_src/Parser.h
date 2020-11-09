#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>

class Parser {
private:
	std::stringstream mensaje;
public:
	Parser(const std::string& _mensaje);
	std::string obtenerPalabra();
	std::string obtenerContenido();
	~Parser();
};

#endif
