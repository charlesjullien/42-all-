#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main(int ac, char **av)
{
	//const Animal* meta = new Animal(); pas le droit car classe abstraite
	const Animal* j = new Dog();
	const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl; 

   
	i->makeSound(); //will output the cat sound!
	j->makeSound();
    //meta->makeSound(); ==> pareil du coup

	std::cout << std::endl;
    std::cout << std::endl;


	delete i;
	delete j;

	return (0);	
}
