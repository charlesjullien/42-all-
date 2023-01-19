#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignation constructor called." << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow... but wrong" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

