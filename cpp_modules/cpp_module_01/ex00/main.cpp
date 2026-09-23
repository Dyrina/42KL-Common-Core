/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:23:06 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/14 16:23:06 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie* zomb;

	zomb = newZombie("Jane");
	zomb->announce();
	randomChump("Ellen");
	delete zomb;
}