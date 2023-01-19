#include "../includes/Serialisation.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main (int ac, char **av)
{
	Data *ptr = new Data;
	ptr->lol = "Hello World!";
	ptr->n1 = 22.0;
	ptr->n2 = 42;


	std::cout << "ptr address before serialization : " << ptr << std::endl;
	std::cout << "struct content before serialization : " << std::endl;
	std::cout << ptr->lol << std::endl;
	std::cout << ptr->n1 << std::endl;
	std::cout << ptr->n2 << std::endl;
	std::cout << std::endl;


	uintptr_t raw = serialize(ptr);//on crée un var raw de type unintptr_t, elle stocke le retour de la ft serialize qui a pour valeur l'addresse de ptr castée en gros int

	std::cout << "raw address after serialization : " << raw << std::endl;

    ptr = deserialize(raw);//la var qui ressemble à un gros int est recastée en addresse... on récupère donc l'adresse de ptr de base qui mène à la struct Data;

	std::cout << "ptr address after deserialization : " << ptr << std::endl;

	std::cout << std::endl;
	std::cout << "struct content after serialization : " << std::endl;
	std::cout << ptr->lol << std::endl;
	std::cout << ptr->n1 << std::endl;
	std::cout << ptr->n2 << std::endl;

	delete ptr;

	return (0);
}