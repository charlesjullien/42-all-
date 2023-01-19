#include "../includes/Character.hpp"

Character::Character()
{
	int i = 0;

	_name = "Unknown";
	while (i < 4)
	{
		materia[i] = NULL;
		i++;
	}
}

Character::Character(const std::string& name)
{
	int i = 0;

	_name = name;
	while (i < 4)
	{
		materia[i] = NULL;
		i++;
	}
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	int i = 0;

	_name = other.getName();
	while (i < 4)
	{
		const AMateria *ptr = other.get_materia(i);
		if (other.get_materia(i))
			materia[i] = ptr->clone();
		else
			materia[i] = NULL;
		i++;
	}
	return (*this);
}

std::string const & Character::getName() const
{
    return (_name);
}

const AMateria* Character::get_materia(int i) const
{
    if (i >= 0 && i <= 3)
        return (materia[i]);
	else
    	return (NULL);
}

void Character::equip(AMateria* m)
{
	int i = 0;

	while (i < 4)
	{
		if (!materia[i])
        {
            materia[i] = m;
            return ;
        }
		i++;
	}
}

void Character::unequip(int idx)
{
	int i = 0;
    if (idx < 0 || idx > 3 || !materia[idx])
        return ;
    materia[idx] = NULL;
	while (idx < 4)
	{
		if ((idx + 1) < 4 && materia[idx + 1])
			materia[idx] = materia[idx + 1];
		if (idx == 3 && materia[idx])
			materia[idx] = NULL;
		idx++;
	}
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3 && materia[idx])
    	materia[idx]->use(target);
}

Character::~Character()
{
	int i = 0;

	while (i < 4)
	{
		if (materia[i])
			delete materia[i];
		i++;
	}
}

