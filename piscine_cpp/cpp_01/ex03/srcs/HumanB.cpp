#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
	std::cout << _name << " created" << std::endl;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}


HumanB::~HumanB()
{
	std::cout << _name << " destroyed" << std::endl;
}