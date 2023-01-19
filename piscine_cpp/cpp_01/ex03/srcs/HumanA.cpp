#include "../includes/HumanA.hpp"
#include "../includes/Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << _name << " created" << std::endl;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << _name << " destroyed" << std::endl;
}