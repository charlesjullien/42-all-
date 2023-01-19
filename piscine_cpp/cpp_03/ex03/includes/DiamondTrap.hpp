#ifndef DiamondTRAP_HPP
# define DiamondTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	virtual ~DiamondTrap();


	const std::string& get_name(void) const;
	const std::string& get_parent_name(void) const;

	using FragTrap::get_hp;
    using ScavTrap::get_mana;
    using FragTrap::get_ad;

    using ScavTrap::attack;
    using ScavTrap::takeDamage;
    using ScavTrap::beRepaired;


	void whoAmI();

	private:

	std::string _name;
	using FragTrap::_hp;
    using ScavTrap::_mana;
    using FragTrap::_ad;
	
};

#endif
