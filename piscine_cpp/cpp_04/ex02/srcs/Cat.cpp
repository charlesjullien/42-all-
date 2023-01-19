#include "../includes/Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	type = "Cat";
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

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
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

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation constructor called." << std::endl;
	type = other.type;
	*B = *(other.B);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void Cat::define_cat_ideas(int i, const std::string& str)
{
   return(B->define_ideas(i, str));
}

const std::string& Cat::get_cat_ideas(int i) const
{
    return (B->get_ideas(i));
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete B;
}

