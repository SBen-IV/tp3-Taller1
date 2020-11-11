#include "Archivo.h"
#include "ErrorArchivo.h"

Archivo::Archivo(const char* nombre_archivo) {
	this->archivo.open(nombre_archivo, std::fstream::in);

	if (!this->archivo.good()) throw ErrorArchivo("%s no es un"
													" archivo válido.",
													nombre_archivo);
}

void Archivo::leer(std::string& linea) {
	std::getline(this->archivo, linea);
}

bool Archivo::esEOF() {
	return this->archivo.eof();
}

Archivo::~Archivo() {
	if (this->archivo.is_open()) this->archivo.close();
}
