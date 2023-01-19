#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(int ac, char **av)
{
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound(); //will output the cat sound!
	j->makeSound();
    meta->makeSound();

	/*********************/

	delete meta;
	delete i;
	delete j;

	/*********************/

	std::cout << "\n\nAnd now with \"Wrong\" Classes :\n\n" << std::endl;

	const WrongAnimal* metab = new WrongAnimal(); 
	const WrongAnimal* k = new WrongCat();

	std::cout << k->getType() << " " << std::endl; 
	k->makeSound(); //will output the cat sound!
    metab->makeSound();

	delete metab;
	delete k;




    
	return (0);	
}
