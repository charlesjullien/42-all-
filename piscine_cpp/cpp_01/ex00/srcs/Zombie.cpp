#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Zombie constructor called for " << _name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie* Zombie::newZombie(std::string name)
{
	return (new Zombie(name));
}

void Zombie::randomChump(std::string name)
{
	Zombie newZombie(name);
	newZombie.announce();
}

Zombie::~Zombie()
{
	std::cout << _name << " died" << std::endl;
	return ;
}