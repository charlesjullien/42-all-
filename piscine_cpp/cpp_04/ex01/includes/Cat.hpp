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

	void define_cat_ideas(int i, const std::string& str);
	const std::string& get_cat_ideas(int i) const;

	private:

	Brain *B;

	
};

#endif
