#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( const std::string newName)
{
	name = newName;
}

Zombie::~Zombie()
{
	std::cout << name << ": destructor called\n";
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}