#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie *horde;

	horde = new Zombie[N];
	while (i < N)
	{
		horde[i].set_name(name, i);
		i++;
	}
	return (horde);
}