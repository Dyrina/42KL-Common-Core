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
#include <iostream>

int main() {
    std::cout << "Basic Actions & Constructors\n";
    ClapTrap clap("Clappy");
    ClapTrap target("TargetDummy");

    clap.attack("TargetDummy");
    target.takeDamage(0);
    target.beRepaired(5);

    std::cout << "\nEnergy Depletion Test\n";
    for (int i = 0; i < 11; i++) {
        clap.attack("a training dummy");
    }

    std::cout << "\nDeath & Action Guard Test\n";
    ClapTrap deadBot("DeadBot");
    deadBot.takeDamage(20);
    deadBot.attack("anyone");
    deadBot.beRepaired(10);

    std::cout << "\nDestructors\n";
    return 0;
}