#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(std::string const & type) : AMateria(type)
{

}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	_type = "ice";
	return (*this);
}

AMateria* Ice::clone() const
{
	try
    {
        AMateria* mat = new Ice;
        return mat;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}
void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{

}

