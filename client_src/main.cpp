#include <iostream>

#include "Comunicador.h"

#define POS_IP 1
#define POS_PUERTO 2

#define MIN_ARGS 3

int main(int argc, char const *argv[]) {
	if (argc < MIN_ARGS) {
		std::cout << "./client <ip/hostname> <port/service>" << std::endl;
		return 0;
	}

	try {
		Comunicador comunicador(argv[POS_IP], argv[POS_PUERTO]);

		comunicador();

		return 0;
	} catch(const std::exception& e) {
		printf("%s\n", e.what());
		return 0;
	} catch(...) {
		printf("Error.\n");
		return 0;
	}
}
