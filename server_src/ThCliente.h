#ifndef THCLIENTE_H
#define THCLIENTE_H

#include <atomic>
#include "../common_src/Thread.h"
#include "../common_src/Peer.h"
#include "../common_src/Parser.h"

class ThCliente : public Thread {
private:
	std::atomic<bool> mantener_conexion;
	std::atomic<bool> esta_conectado;
	Peer peer;
public:
	ThCliente(Peer& _peer);
	virtual void run() override;
	virtual void stop() override;
	virtual ~ThCliente();
};

#endif
