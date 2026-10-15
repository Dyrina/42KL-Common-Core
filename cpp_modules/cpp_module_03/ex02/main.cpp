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

#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "Constructor & Destructor Chaining Test\n";
    {
        FragTrap frag("Fraggy");
    } 
    std::cout << "Stats & Action Tests (30 Attack Damage)\n";
    {
        FragTrap frag("Clappy-Destroyer");
        frag.attack("a dummy target");
        frag.takeDamage(50);
        frag.beRepaired(25);
    }
    std::cout << "Speical Ability: highFivesGuys\n";
    {
        FragTrap frag("HighFiveBot");
        frag.highFivesGuys();
    }
    std::cout << "Orthodox Canonical From Test\n";
    {
        FragTrap original("Original");
        FragTrap copy(original);
        FragTrap assigned("Assigned");
        assigned = original;
        std::cout << "\nTriggering actions on copied objects:\n";
        copy.highFivesGuys();
        assigned.highFivesGuys();
    }
    std::cout << "Edge Cases (0 HP Behavior)\n";
    {
        FragTrap deadFrag("DeadBot");

        deadFrag.takeDamage(200);
        deadFrag.attack("an enemy");
        deadFrag.beRepaired(50);
        deadFrag.highFivesGuys();
    }
    return 0;
}