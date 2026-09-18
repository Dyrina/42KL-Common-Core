#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string		name;
		const Weapon*	weapon;

	public:
		HumanB( const std::string newName );
		~HumanB();
		void	setWeapon( const Weapon& newWeapon );
		void	attack();
};

#endif