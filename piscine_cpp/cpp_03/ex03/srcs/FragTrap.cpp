#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called for " << name << std::endl;
	std::cout << std::endl;
}


FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignation constructor called" << std::endl;
	_name = other.get_name();
	_hp = other.get_hp();
	_mana = other.get_mana();
	_ad = other.get_ad();

	return (*this);
}


void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " is making a high five." <<  std::endl;
}

/*
void FragTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
	std::cout << "... but this attack was called from FragTrap (ClapTrap daughter) as it used a mask" << std::endl;
}
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

