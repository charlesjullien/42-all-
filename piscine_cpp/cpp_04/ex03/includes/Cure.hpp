#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:

	Cure();
	Cure(std::string const & type);
	Cure(const Cure &other);

	virtual Cure &operator=(const Cure &other);
	virtual ~Cure();

	virtual AMateria* clone() const;
	
    virtual void use(ICharacter& target);

	protected:

	std::string _type;


};

#endif
