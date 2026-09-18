#include "HumanB.hpp"

HumanB::HumanB( const std::string newName)
{
	name = newName;
	weapon = NULL;
}

HumanB::~HumanB() {};

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << "\n";
}

void	HumanB::setWeapon( const Weapon& newWeapon )
{
	weapon = &newWeapon;
}