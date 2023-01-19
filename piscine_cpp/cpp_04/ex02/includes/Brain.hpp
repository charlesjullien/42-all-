#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:

	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void define_ideas(int i, const std::string& str);
	const std::string& get_ideas(int i) const;

	private:

	protected :
	
	std::string ideas[100];
};

#endif
