#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string		name;
		const Weapon&	weapon;

	public:
		HumanA( const std::string newName, const Weapon& newWeapon );
		~HumanA();
		void	attack();
};

#endif