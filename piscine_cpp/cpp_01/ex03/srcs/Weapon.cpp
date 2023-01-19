#include "../includes/Weapon.hpp"

Weapon::Weapon()
{
	
}

Weapon::Weapon(std::string name)
{
	_type = name;
}

std::string const &Weapon::getType(void) const
{
	return (this->_type);
}
void Weapon::setType(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{
	std::cout << "Weapon class destroyed" << std::endl;
}