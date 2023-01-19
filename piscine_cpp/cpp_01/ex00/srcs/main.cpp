#include "../includes/Zombie.hpp"

int main()
{
	Zombie z("Robert");
	z.announce();
	Zombie *nz = z.newZombie("Guy");
	nz->announce();

	z.randomChump("Francis");
	delete nz;

	return (0);
}