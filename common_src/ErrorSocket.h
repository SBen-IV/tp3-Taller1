#ifndef ERRORSOCKET_H
#define ERRORSOCKET_H

#include <exception>
#include <cstring>
#include <cerrno>

#define MAX_MSJ_ERROR 200

//ErrorSocket es una excepción que guarda un mensaje de error usado por la
//clase Socket

class ErrorSocket : public std::exception {
private:
	char msj_error[MAX_MSJ_ERROR];
public:
	ErrorSocket() noexcept;
	explicit ErrorSocket(const char* mensaje) noexcept;
	virtual const char* what() const noexcept;
	virtual ~ErrorSocket();
};

#endif
