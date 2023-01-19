#include "../includes/ClapTrap.hpp"

int main(int ac, char **av)
{
	ClapTrap Zemmour("Zemmour");
	ClapTrap Pecresse("Pecresse");
	ClapTrap Macron("Macron");

	Zemmour.attack("Pecresse");
	Pecresse.takeDamage(4);
	Zemmour.attack("Pecresse");
	Pecresse.takeDamage(2);
	Pecresse.beRepaired(3);
	Pecresse.beRepaired(3);

	Pecresse.attack("Zemmour");
	Zemmour.takeDamage(0);

	Pecresse.attack("Macron");
	Macron.takeDamage(10);
	Macron.beRepaired(1);

	Zemmour.attack("Pecresse");
	Pecresse.takeDamage(10);
	Pecresse.beRepaired(10);

	return (0);	
}
