#include <iostream>
#include <thread>
#include <vector>

#include "GestorDeClientes.h"

#define ESPACIO ' '
#define CARACTER_CORTE 'q'

int main(int argc, char const *argv[]) {
	if (argc < 3) {
		std::cout << "./server <puerto/servicio> <root_file>" << std::endl;
		return 0;
	}

	try {
		std::vector<std::thread> threads;

		for (size_t i; i < 1; ++i) {
			threads.push_back(std::thread {GestorDeClientes(argv[1],
															argv[2])});
		}

		char c = ESPACIO;

		while (c != CARACTER_CORTE) {
			std::cin.get(c);
		}

	//	this->gestor();
	//	gestor.finalizar(); // close(socket)
		for (size_t i; i < 1; ++i) {
			threads[i].join();
		}
		return 0;

	} catch(const std::exception& e) {
		printf("%s\n", e.what());
		return 0;

	} catch(...) {
		printf("Error.\n");
		return 0;
	}
	return 0;
}
