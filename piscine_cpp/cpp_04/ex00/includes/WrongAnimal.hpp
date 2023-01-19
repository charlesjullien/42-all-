#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	virtual ~WrongAnimal();

	const std::string& getType() const;

	void makeSound() const;

	private:

	protected :

	std::string type;


};

#endif
