#include "../includes/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
	type = "Dog";
	try
    {
        B = new Brain();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        throw e;
    }
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	try
    {
        B = new Brain();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        throw e;
    }
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation constructor called." << std::endl;
	type = other.type;
	*B = *(other.B);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouaf" << std::endl;
}

void Dog::define_dog_ideas(int i, const std::string& str)
{
   return(B->define_ideas(i, str));
}

const std::string& Dog::get_dog_ideas(int i) const
{
    return (B->get_ideas(i));
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete B;
}

