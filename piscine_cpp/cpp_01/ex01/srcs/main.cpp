#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main ()
{
	int N = 7;
	int i = 0;
	Zombie *zh;

	zh = zombieHorde(N, "Zozo");
	while (i < N)
	{
		zh[i].announce();
		i++;
	}
	delete [] zh;
	return (0);
}