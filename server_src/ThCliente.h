#ifndef THCLIENTE_H
#define THCLIENTE_H

#include <atomic>
#include "../common_src/Thread.h"
#include "../common_src/Peer.h"
#include "../common_src/Parser.h"
#include "../common_src/Recursos.h"

class ThCliente : public Thread {
private:
	std::atomic<bool> mantener_conexion;
	std::atomic<bool> esta_conectado;
	Recursos& recursos;
	Peer peer;
public:
	ThCliente(Peer& _peer, Recursos& _recursos);
	virtual void run() override;
	virtual void stop() override;
	~ThCliente();
};

#endif
