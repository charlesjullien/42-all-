#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
	public:

	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

	virtual void makeSound() const;

	void define_dog_ideas(int i, const std::string& str);
	const std::string& get_dog_ideas(int i) const;

	private:

	Brain *B;


};

#endif
