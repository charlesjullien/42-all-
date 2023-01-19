#include "../includes/Bureaucrat.hpp"

int main(int ac, char **av)
{
    Bureaucrat Asselineau("Asselineau", 9);
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
	return (0);	
}
