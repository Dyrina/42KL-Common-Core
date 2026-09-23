/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:39:33 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 15:30:07 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string newType )
{
	type = newType;
};

Weapon::~Weapon() {};

const std::string&	Weapon::getType() const
{
	return type;
}

void	Weapon::setType( const std::string newType )
{
	type = newType;
}