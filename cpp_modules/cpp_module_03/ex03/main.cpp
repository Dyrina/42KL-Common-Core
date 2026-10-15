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

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "Constructor & Destructor Chaining\n";
	{
        DiamondTrap diamond("Sparkle");

        std::cout << "Stats & Functions\n";
        diamond.whoAmI();
        diamond.attack("a target dummy");
        diamond.guardGate();
        diamond.highFivesGuys();
	}
	return 0;
}