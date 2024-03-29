#include <iostream>
#include <thread>
#include <vector>

#include "GestorDeClientes.h"

#define ESPACIO ' '
#define CARACTER_CORTE 'q'

#define POS_PUERTO 1
#define POS_ROOT_FILE 2

#define MIN_ARGS 3

int main(int argc, char const *argv[]) {
	if (argc < MIN_ARGS) {
		std::cout << "./server <puerto/servicio> <root_file>" << std::endl;
		return 1;
	}

	try {
		GestorDeClientes gestor(argv[POS_PUERTO], argv[POS_ROOT_FILE]);
		std::thread main_thread(&GestorDeClientes::operator(), &gestor);

		char c = ESPACIO;

		while (c != CARACTER_CORTE) {
			std::cin >> c;
		}

		gestor.finalizar();
		main_thread.join();

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
