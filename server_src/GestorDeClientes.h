#ifndef GESTORDECLIENTES_H
#define GESTORDECLIENTES_H

#include <string>

#include "../common_src/Socket.h"
#include "../common_src/Recursos.h"
#include "../common_src/Thread.h"

class GestorDeClientes : public Thread {
private:
	Socket socket;
	Recursos recursos;
public:
	GestorDeClientes(const char* puerto, const char* _archivo_raiz);
//	void operator()();
	void run() override;
	void stop() override;
	~GestorDeClientes();
};

#endif
