#ifndef ERRORCONECTAR_H
#define ERRORCONECTAR_H

#include <exception>
#include <cstring>

#define MAX_MSJ_ERROR 200

class ErrorConectar : public std::exception {
private:
	char msj_error[MAX_MSJ_ERROR];
public:
	explicit ErrorConectar(const char* mensaje) noexcept;
	virtual const char* what() const noexcept;
	virtual ~ErrorConectar();
};

#endif
