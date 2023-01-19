#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name, int num)
{
	char c;

	c = num + 48;
	_name = name;
	_name += " ";
	_name += c;
}

	
Zombie::~Zombie()
{
	std::cout << _name << " died" << std::endl;
}