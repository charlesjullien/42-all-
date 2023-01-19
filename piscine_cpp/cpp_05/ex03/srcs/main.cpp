#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main(int ac, char **av)
{
    Intern someRandomIntern;
    Form *rob;
    Form *presid;
    Form *shrub;
    Bureaucrat Mario("Mario", 3);
    Bureaucrat Toad("Toad", 24);
    Bureaucrat Yoshi("Yoshi", 72);

    try
    {
        rob = someRandomIntern.makeForm("robotomy request", "Jean-Jacques");
        Mario.signForm(*rob);
        Mario.executeForm(*rob);//nothing happens (action is abstract in Form)
        //rob->action();//nothing happens (action is private in Form) ==> + non virtual and pub in Z
        std::cout << std::endl;
        presid = someRandomIntern.makeForm("presidential pardon", "Guy-Francis");
        Toad.signForm(*presid);
        Toad.executeForm(*presid);
      //  presid->action();
        std::cout << std::endl;
        shrub = someRandomIntern.makeForm("shrubbery creation", "Bob-René");
        Yoshi.signForm(*shrub);
        Yoshi.executeForm(*shrub);
      //  shrub->action();
        delete rob;
        delete presid;
        delete shrub;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }

	return (0);	
}
