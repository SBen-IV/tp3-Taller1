#ifndef GESTORDECLIENTES_H
#define GESTORDECLIENTES_H

#include <map>
#include <string>

#include "../common_src/Socket.h"

class GestorDeClientes {
private:
	Socket socket;
	const std::string archivo_raiz;
	std::map<std::string, std::string> recursos;
public:
	GestorDeClientes(const char* puerto, const char* _archivo_raiz);
	void operator()();
	~GestorDeClientes();
};

#endif
