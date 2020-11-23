#ifndef THCLIENTE_H
#define THCLIENTE_H

#include <atomic>
#include <string>
#include "../common_src/Thread.h"
#include "../common_src/Peer.h"
#include "../common_src/Parser.h"
#include "../common_src/RecursosProtected.h"

//ThCliente hereda de Thread y se encarga de la comunicación con el cliente
//como un servidor.

class ThCliente : public Thread {
private:
	std::atomic<bool> esta_conectado;
	RecursosProtected& recursos;
	Peer peer;
public:
	ThCliente(Peer& _peer, RecursosProtected& _recursos);
	void run() override;
	void stop() override;
	bool termino() override;
	~ThCliente();
private:
	void obtenerPetitorio(std::string& petitorio);
};

#endif
