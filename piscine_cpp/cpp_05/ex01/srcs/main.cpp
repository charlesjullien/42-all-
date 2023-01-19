#include "../includes/Bureaucrat.hpp"

int main(int ac, char **av)
{
    Bureaucrat Asselineau("Asselineau", 9);
    Bureaucrat Pecresse("Pecresse", 140);
    Asselineau.rise_grade();
    std::cout << "increment: " << Asselineau << std::endl;
    Asselineau.lower_grade();
    std::cout << "decrement: " << Asselineau << std::endl;

    std::cout << std::endl;
    try
    {
        Bureaucrat Castex(-1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Veran(151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Macron(149);
        Macron.rise_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Sarko(150);
        Sarko.lower_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    //

    Form A1("A1", 19, 25);
    Form A2(48, 48);
    Form A3;

    std::cout << Asselineau << std::endl;
    std::cout << Pecresse << std::endl;
    std::cout << A1 << std::endl;
    std::cout << A2 << std::endl;
    std::cout << A3 << std::endl;


    try 
    {
        Asselineau.signForm(A1);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: "<< e.what() << std::endl;
    }

    try 
    {
        Pecresse.signForm(A2);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: "<< e.what() << std::endl;
    }

    try 
    {
        Pecresse.signForm(A3);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: "<< e.what() << std::endl;
    }
	return (0);	
}
