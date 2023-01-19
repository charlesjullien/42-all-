#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"


class ShrubberyCreationForm : public Form
{
	public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	explicit ShrubberyCreationForm(const std::string target);
	
	private:

	virtual void action() const;
	
};

#endif
