#ifndef INTERN_H
# define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp" 

class Intern
{
	public:
	
	class Error : public std::exception
    {
        virtual const char* what() const throw();
    };

	Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern &other);
	~Intern();
	
	Form *makeForm(const std::string form, const std::string target);

	Form *Shrubbery(const std::string& target) const;
	Form *Robotomy(const std::string& target) const;
	Form *Presidential(const std::string& target) const;
	
};
	
#endif