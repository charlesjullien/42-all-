#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	int i = 0;

	std::cout << "Brain assignation constructor called." << std::endl;
	while (i < 100)
	{
		this->define_ideas(i, other.get_ideas(i));
		i++;
	}
	return (*this);
}

void Brain::define_ideas(int i, const std::string& str)
{
    if (i >= 0 && i < 100)
        ideas[i] = str;
	else
		std::cerr << "index must be in range of array range... between 0 and 99 included." << std::endl;

}

const std::string& Brain::get_ideas(int i) const
{
    if (i >= 0 && i < 100)
        return (ideas[i]);
	else
	{
		std::cerr << "index must be in range of array range... between 0 and 99 included." << std::endl;
    	return (ideas[0]);
	}
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

