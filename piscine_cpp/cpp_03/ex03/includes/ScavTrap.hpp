#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	virtual ~ScavTrap();

	void guardGate();
	void attack(const std::string& target);

	private:

	
};

#endif
