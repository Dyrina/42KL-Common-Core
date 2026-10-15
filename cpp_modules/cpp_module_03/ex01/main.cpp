/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 12:13:01 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/11 12:13:01 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "Constructor / Destructor Chaining Test\n";
    {
    	ScavTrap scav("Serena");
    }
    std::cout << "\nAttack & Damage Test (Checking 20 Damage)\n";
    {
    	ClapTrap clap("Clappy");
     	ScavTrap scav("Scavvy");

      	clap.attack("a training dummy");
       	scav.attack("a training dummy");
        scav.takeDamage(30);
        scav.beRepaired(15);
    }
    std::cout << "\nSpecial Ability Test\n";
    {
        ScavTrap scav("Gatekeeper-01");
        scav.guardGate();
    }
    std::cout << "\nDeath & Defeat Test\n";
    {
        ScavTrap scav("UnluckyScav");
        scav.takeDamage(150);
        scav.attack("an enemy");
        scav.beRepaired(20);
        scav.guardGate();
    }
    return 0;
}
