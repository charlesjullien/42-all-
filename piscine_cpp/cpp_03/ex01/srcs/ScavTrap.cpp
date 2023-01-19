#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for " << name << std::endl;
	std::cout << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignation constructor called" << std::endl;
	_name = other.get_name();
	_hp = other.get_hp();
	_mana = other.get_mana();
	_ad = other.get_ad();

	return (*this);
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." <<  std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
	std::cout << "... but this attack was called from ScavTrap (ClapTrap daughter) as it used a mask" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

