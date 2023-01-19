#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called." << std::endl;
	//type = "Animal";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation constructor called." << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "[...Animal Sound...]" << std::endl;
}

const std::string& Animal::getType() const
{
    return (type);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

