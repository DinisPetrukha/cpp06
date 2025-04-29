#include "Identify.hpp"

int main() {
	// Inicializar o gerador de números aleatórios
	srand(static_cast<unsigned int>(time(0)));

	// Gerar um objeto aleatório
	Base* obj = generate();

	// Identificar o tipo usando ponteiro
	std::cout << "Identificando via ponteiro:" << std::endl;
	identify(obj);

	// Identificar o tipo usando referência
	std::cout << "\nIdentificando via referência:" << std::endl;
	identify(*obj);

	// Limpar memória alocada
	delete obj;

	return 0;
}
