#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie* zomb;

	zomb = newZombie("simmy");
	zomb->announce();
	randomChump("sim");
	delete zomb;
}