#ifndef FragTRAP_HPP
# define FragTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();

	//void attack(const std::string& target);

	void highFivesGuys(void);

	private:

	
};

#endif
