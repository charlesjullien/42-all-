#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(std::string const & type) : AMateria(type)
{

}

Cure::Cure(const Cure &other)
{
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	_type = "cure";
	return (*this);
}

AMateria* Cure::clone() const
{
	try
    {
        AMateria* mat = new Cure;
        return mat;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}
void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{

}

