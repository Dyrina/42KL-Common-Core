#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	Zombie*	horde;
	int		nZombie = 50;

	horde = zombieHorde(nZombie, "bob_dylan");
	for (int i = 0; i < nZombie; ++i)
	{
		horde[i].announce();
	}
	delete[] horde;
}