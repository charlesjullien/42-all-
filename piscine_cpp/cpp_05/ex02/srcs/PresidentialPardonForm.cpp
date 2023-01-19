#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardon", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): Form("PresidentialPardon", 25, 5, target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	return (*this);
}

void PresidentialPardonForm::action() const
{
	std::cout << get_target() << " has been forgiven by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

