/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:43:07 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/12 18:43:07 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() :
	ClapTrap("default_clap_name"),
	FragTrap(),
	ScavTrap(),
	m_name("default")
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
    std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	m_name(name)
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
    std::cout << "DiamondTrap " << m_name << " created!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other),
	FragTrap(other),
	ScavTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap " << m_name << " copy constructed!\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		m_name = other.m_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << m_name << " destroyed!\n";
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap: " << m_name 
		<< " | My ClapTrap name is: " << ClapTrap::m_name << "\n";
}
