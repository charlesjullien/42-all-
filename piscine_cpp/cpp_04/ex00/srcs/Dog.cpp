#include "../includes/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation constructor called." << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouaf" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

