#ifndef ERRORARCHIVO_H
#define ERRORARCHIVO_H

#include <exception>

#define MAX_MSJ_ERROR 200

//ErrorArchivo es una excepción que guarda un mensaje de error que fue
//ocacionado en la clase Archivo, se lo puede leer en el método what().

class ErrorArchivo : public std::exception {
private:
	char msj_error[MAX_MSJ_ERROR];
public:
	ErrorArchivo(const char* formato, ...) noexcept;
	virtual const char* what() const noexcept;
	virtual ~ErrorArchivo();
};

#endif
