/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 23:03:58 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/11 23:03:58 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : 
	ClapTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap( const std::string newName ) :
	ClapTrap(newName)
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "ScavTrap " << m_name << " constructed!\n";
}

ScavTrap::ScavTrap( const ScavTrap& other ) :
	ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap " << m_name << " copy constructed!\n";
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& other )
{
	std::cout << "ScavTrap Copy assignment operator called\n";
	if (this != &other)
	{
		m_name = other.m_name;
		m_hitPoints = other.m_hitPoints;
		m_energyPoints = other.m_energyPoints;
		m_attackDamage = other.m_attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << m_name << " destroyed!\n";
}

void	ScavTrap::attack( const std::string& target )
{
    if (m_hitPoints == 0)
    {
        std::cout << "ScavTrap " << m_name << " cannot attack because it is out of hit points!\n";
        return;
    }
    if (m_energyPoints == 0)
    {
        std::cout << "ScavTrap " << m_name << " cannot attack because it has no energy points left!\n";
        return;
    }
    m_energyPoints--;
    std::cout << "ScavTrap " << m_name << " viciously attacks " << target 
              << ", causing " << m_attackDamage << " points of damage!\n";
}

void	ScavTrap::guardGate()
{
	if (m_hitPoints == 0)
	{
        std::cout << "ScavTrap " << m_name << " cannot enter Gate keeper mode because it is destroyed!\n";
        return;
    }
    std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode!\n";
}
