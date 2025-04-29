#include "Serialize.hpp"

int main() {
	// Criar e preencher uma estrutura Data
	Data original;
	original.num = 42;
	original.str = "Olá mundo!";

	// Mostrar dados originais
	std::cout << "Original Data:" << std::endl;
	std::cout << "  num: " << original.num << std::endl;
	std::cout << "  str: " << original.str << std::endl;

	// Serializar
	uintptr_t raw = Serialize::serialize(&original);
	std::cout << "\nSerialized pointer as integer: " << raw << std::endl;

	// Desserializar
	Data* restored = Serialize::deserialize(raw);

	// Confirmar que os ponteiros são equivalentes
	std::cout << "\nRestored Data:" << std::endl;
	std::cout << "  num: " << restored->num << std::endl;
	std::cout << "  str: " << restored->str << std::endl;

	// Comparar ponteiros
	if (restored == &original)
		std::cout << "\n[✔] Pointers match. Serialization and deserialization succeeded!" << std::endl;
	else
		std::cout << "\n[✘] Pointers do not match. Something went wrong." << std::endl;

	return 0;
}
