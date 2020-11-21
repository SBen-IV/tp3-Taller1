#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>

//Archivo encapsula los métodos para abrir, leer y cerrar un archivo cuyo
//nombre fue pasado por el constructor.

class Archivo {
private:
	std::fstream archivo;
public:
	explicit Archivo(const char* nombre_archivo);
	void leer(std::string& linea);
	bool esEOF();
	~Archivo();
};

#endif
