#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:

	MateriaSource();
	MateriaSource(const MateriaSource &other);

	virtual MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);

	const AMateria *get_materia(int i) const;

	private:

	AMateria *materia[4];
};

#endif
