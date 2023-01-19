#include "../includes/Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation constructor called." << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}


Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

