#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:

	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();

	virtual void makeSound() const;

	private:

	
};

#endif
