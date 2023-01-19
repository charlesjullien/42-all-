#include "../includes/Atoicfd.hpp"

//nan == "not a number"
//-inf == "negative infinity"
//inf == "positive infinity"
//

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : program accepts only one argument. Not less, not more." << std::endl;
		return (1);
	}
	try
	{
		Atoicfd convert(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}