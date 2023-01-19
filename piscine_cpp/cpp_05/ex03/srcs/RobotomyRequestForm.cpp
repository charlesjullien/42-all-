#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequest", 72, 45)
{
    
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): Form("RobotomyRequest", 72, 45, target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	return (*this);
}

void RobotomyRequestForm::action() const
{
	if (rand() % 2)
    {
        std::cout << "[Takakakakakakakakakak]!  [" << get_target() << "] has been robotomized." << std::endl;
    }
    else
    {
        std::cout << "[Takakakakakakakakakak]!  [" << get_target() << "] has failed to be robotomized." << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

