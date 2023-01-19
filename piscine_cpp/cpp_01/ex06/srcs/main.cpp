#include "../includes/Harl.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage : ./HarlFilter [level]" << std::endl;
		return (1);
	}
	std::string	level = av[1];

	Harl k;
	std::cout << std::endl;
	k.complain(level);

	return (0);
}