/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 12:13:15 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/11 12:13:15 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
	m_name(""),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{};

ClapTrap::ClapTrap( const std::string newName ) :
	m_name(newName),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{
	std::cout << "ClapTrap " << newName << ": Constructor called\n";
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
	*this = other;
	std::cout << "ClapTrap " << m_name << ": Copy Constructor called\n";
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other )
{
	if (this != &other)
	{
		m_name = other.m_name;
		m_hitPoints = other.m_hitPoints;
		m_energyPoints = other.m_energyPoints;
		m_attackDamage = other.m_attackDamage;
	}
	std::cout << "ClapTrap " << m_name << ": Copy assignment operator called\n";
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << m_name << ": Destructor called\n";
};

void	ClapTrap::attack( const std::string& target )
{
	if (m_energyPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " has no more energy\n";
		return ;
	}
	else if (m_hitPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " is dead\n";
		return ;
	}
	m_energyPoints -= 1;
	std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing ";
	std::cout << m_attackDamage << " points of damage!\n";
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (m_hitPoints - amount > m_hitPoints)
		m_hitPoints = 0;
	else
		m_hitPoints -= amount;
	std::cout << "ClapTrap " << m_name << " takes " << amount;
	std::cout << " points of damage! " << m_hitPoints << " hitpoints left!\n";
	if (m_hitPoints == 0)
		std::cout << "ClapTrap " << m_name << " is dead\n";
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (m_energyPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " has no more energy\n";
		return ;
	}
	else if (m_hitPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " is dead\n";
		return ;
	}
	m_energyPoints -= 1;
	m_hitPoints += amount;
	std::cout << "ClapTrap " << m_name << " repairs " << amount << " of hitpoints!\n";
}