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

int	main(void)
{
	ClapTrap	player1("Dylan");

	player1.attack("Sim");
	player1.takeDamage(5);
	player1.takeDamage(10);
	player1.beRepaired(5);
}