#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "default constructor called... _name value is \"Nobody\"" << std::endl;
	_name = "nobody";
	_hp = 100;
	_mana = 50;
	_ad = 20;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
	_name = name;
	_hp = 100;
	_mana = 50;
	_ad = 20;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignation constructor called" << std::endl;
	_name = other.get_name();
	_hp = other.get_hp();
	_mana = other.get_mana();
	_ad = other.get_ad();

	return (*this);
}

/*  ***********************************  */
/*  Fonctions propres à l'exo _ Début :  */
/*  ***********************************  */


void ClapTrap::attack(const std::string& target)
{
	if (_mana == 0)
	{
		std::cout << _name << " cannot attack as he doesn't have any mana point left..." << std::endl;
		return ;
	}
	std::cout << _name << " attacks " << target;
	_mana -= 1;
	if (_mana < 0)
		_mana = 0;
	std::cout << ". He spent 1 mana point in the process. He now has " << _mana << " mana." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << "oops... already dead" << std::endl;
		return ;
	}
	std::cout << _name << " took " << amount << " damage... decreasing his HP to ";
	if ((_hp - amount) < 0)
		_hp = 0;
	else
		_hp = _hp - amount;
	std::cout << _hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_mana == 0)
	{
		std::cout << _name << " cannot heal himself as he doesn't have any mana point left..." << std::endl;
		return ;
	}
	if (_hp == 0)
	{
		std::cout << _name << " cannot heal himself as he is already dead" << std::endl;
		return ;
	}
	std::cout << _name << " healed himself restoring " << amount << " Hit Points. ";
	_mana -= 1;
	if (_mana < 0)
		_mana = 0;
	std::cout << "He spent 1 mana point in the process. He now has " << _mana << " mana." << std::endl;
	_hp += amount;
}

std::string ClapTrap::get_name(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::get_hp(void) const
{
	return (this->_hp);
}

unsigned int ClapTrap::get_mana(void) const
{
	return (this->_mana);
}

unsigned int ClapTrap::get_ad(void) const
{
	return (this->_ad);
}


/*  ***********************************  */
/*  Fonctions propres à l'exo _ Fin :  */
/*  ***********************************  */

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

