#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(int ac, char **av)
{
    /*Bureaucrat chef("chef", 1);
    PresidentialPardonForm bandit("bandit");

    chef.signForm(bandit);
    chef.executeForm(bandit);*/

    std::srand(std::time(NULL));
    {
        PresidentialPardonForm pre("xyz");
        Bureaucrat mec("mec", 1);

        mec.signForm(pre);
        mec.executeForm(pre);
        std::cout << mec << std::endl;
        std::cout << pre << std::endl;
    }

    std::cout << "|------------|" << std::endl;

    {
        PresidentialPardonForm pre("xyz");
        Bureaucrat mec("mec", 10);

        mec.signForm(pre);
        mec.executeForm(pre);
        std::cout << mec << std::endl;
        std::cout << pre << std::endl;
    }

    std::cout << "|------------|" << std::endl;

    {
        PresidentialPardonForm pre("xyz");
        Bureaucrat mec("mec", 1);

        pre.BeSigned(mec);
        pre.execute(mec);
        std::cout << mec << std::endl;
        std::cout << pre << std::endl;
    }

    std::cout << "|------------|" << std::endl;

    {
        PresidentialPardonForm pre("xyz");
        Bureaucrat mec("mec", 1);

        mec.executeForm(pre);
        std::cout << mec << std::endl;
        std::cout << pre << std::endl;
    }

    std::cout << "|------------|" << std::endl;

    {
        RobotomyRequestForm rob("xyz");
        Bureaucrat mec("mec", 1);

        mec.signForm(rob);
        mec.executeForm(rob);
        std::cout << mec << std::endl;
        std::cout << rob << std::endl;
    }

    std::cout << "|------------|" << std::endl;

    {
        RobotomyRequestForm rob("xyz");
        Bureaucrat mec("mec", 1);

        mec.signForm(rob);
        mec.executeForm(rob);
        std::cout << mec << std::endl;
        std::cout << rob << std::endl;
    }

    std::cout << "|------------|" << std::endl;

    {
        RobotomyRequestForm rob("xyz");
        Bureaucrat mec("mec", 1);

        mec.signForm(rob);
        mec.executeForm(rob);
        std::cout << mec << std::endl;
        std::cout << rob << std::endl;
    }

    std::cout << "|------------|" << std::endl;

    {
        ShrubberyCreationForm shr("xyz");
        Bureaucrat mec("mec", 1);

        mec.signForm(shr);
        mec.executeForm(shr);
        std::cout << mec << std::endl;
        std::cout << shr << std::endl;
    }

	return (0);	
}
