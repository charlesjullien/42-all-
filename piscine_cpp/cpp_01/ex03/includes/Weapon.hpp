#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:

	Weapon();
	Weapon(std::string name);
	~Weapon();

	std::string const &getType(void) const;
	void setType(std::string type);


	private:

	std::string _type;
	
};

#endif