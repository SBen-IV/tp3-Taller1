#include <iostream>

#include "../common_src/Comunicador.h"

int main(int argc, char const *argv[]) {
	if (argc < 3) {
		std::cout << "./client <ip/hostname> <port/service>" << std::endl;
		return 0;
	}

	try {
		Comunicador comunicador(argv[1], argv[2]);

		comunicador.conectar();

		comunicador.iniciarCliente();

		return 0;
	} catch(const std::exception& e) {
		printf("%s\n", e.what());
		return 0;
	} catch(...) {
		printf("Error.\n");
		return 0;
	}
}
