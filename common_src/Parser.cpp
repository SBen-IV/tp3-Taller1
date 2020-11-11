#include "Parser.h"

Parser::Parser(const std::string& _mensaje) : mensaje(_mensaje) {}

std::string Parser::obtenerPalabra() {
	std::string palabra;
	this->mensaje >> palabra;

	return palabra;
}

std::string Parser::obtenerContenido() {
	std::string contenido, aux;
	std::getline(this->mensaje, aux, '\n');
	do {
		std::getline(this->mensaje, aux, '\n');
	} while (aux != "" && !this->mensaje.eof()); // Cambiar condicion

	std::getline(this->mensaje, contenido, '\0');

	return contenido;
}

Parser::~Parser() {}
