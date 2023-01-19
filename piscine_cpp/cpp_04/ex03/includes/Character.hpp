#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:

	Character();
	Character(const std::string& name);
	Character(const Character &other);

	virtual Character &operator=(const Character &other);
	virtual ~Character();

	virtual std::string const & getName() const;
    const AMateria* get_materia(int i) const;

	virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

	private:

	std::string _name;
	AMateria *materia[4];
};

#endif
