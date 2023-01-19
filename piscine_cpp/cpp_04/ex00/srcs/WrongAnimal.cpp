#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignation constructor called." << std::endl;
	return (*this);
}

const std::string& WrongAnimal::getType() const
{
    return (type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "[...WrongAnimal Sound...]" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

