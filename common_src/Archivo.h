#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>

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
