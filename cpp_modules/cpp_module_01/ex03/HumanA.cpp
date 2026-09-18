#include "HumanA.hpp"

HumanA::HumanA( const std::string newName, const Weapon& newWeapon ):
weapon(newWeapon)
{
	name = newName;
}

HumanA::~HumanA() {};

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}	