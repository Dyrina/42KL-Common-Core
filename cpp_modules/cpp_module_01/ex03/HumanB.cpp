/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:39:59 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 15:26:26 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

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