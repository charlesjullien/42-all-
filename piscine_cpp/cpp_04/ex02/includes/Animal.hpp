#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	public:

	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const = 0; //le = 0 permet de faire une classe abstraite ca ft virtuelle + utilisée dans les Classes enfant avec le mm prototype

	const std::string& getType() const;

	private:

	protected :
	
	std::string type;
};

#endif
