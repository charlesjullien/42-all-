#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:

	Ice();
	Ice(std::string const & type);
	Ice(const Ice &other);

	virtual Ice &operator=(const Ice &other);
	virtual ~Ice();

	virtual AMateria* clone() const;
	
    virtual void use(ICharacter& target);

	protected:

	std::string _type;
};

#endif
