#include "../includes/Intern.hpp"

Intern::Intern ()
{

}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	return (*this);
}

Form    *Intern::Shrubbery(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

Form    *Intern::Robotomy(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

Form    *Intern::Presidential(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

Form    *Intern::makeForm(std::string form, std::string target)
{
	int i = 0;
	int j;
	std::string request[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *forms[3] = {Intern::Shrubbery(target), Intern::Robotomy(target), Intern::Presidential(target)};
    
	while (i < 3)
	{
		if (request[i] == form)
        {
            std::cout << "Intern creates " << form << std::endl;
			j = 0;
			while (j < 3)
			{
				if (j != i)
					delete forms[j];
				j++;
			}
            return (forms[i]);
		}
		i++;
	}
    throw Error();
	return nullptr;
}

const char *Intern::Error::what() const throw()
{
	return ("Error : Form request doesn't fit criterias\n");
}

Intern::~Intern ()
{

}