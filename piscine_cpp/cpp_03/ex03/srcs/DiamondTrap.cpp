#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NOBODY_clap_name")
{
	_name = "NOBODY";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
	std::cout << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignation constructor called" << std::endl;
	_name = other.get_name();
	_hp = other.get_hp();
	_mana = other.get_mana();
	_ad = other.get_ad();

	return (*this);
}

const std::string& DiamondTrap::get_name(void) const
{
	return (_name);
}

const std::string& DiamondTrap::get_parent_name(void) const
{
	return (this->ClapTrap::_name);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << ".\nMy parent name is " << get_parent_name() << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

