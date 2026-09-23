/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:39:47 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 15:28:41 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( const std::string newName, const Weapon& newWeapon ) :
	weapon(newWeapon)
{
	name = newName;
}

HumanA::~HumanA() {};

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}	