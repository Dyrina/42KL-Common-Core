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
	m_name("Default"),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap( const std::string newName ) :
	m_name(newName),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{
	std::cout << "ClapTrap " << m_name << " constructed!\n";
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
	*this = other;
	std::cout << "ClapTrap " << m_name << " copy constructed!\n";
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other )
{
	std::cout << "ClapTrap Copy assignment operator called\n";
	if (this != &other)
	{
		m_name = other.m_name;
		m_hitPoints = other.m_hitPoints;
		m_energyPoints = other.m_energyPoints;
		m_attackDamage = other.m_attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << m_name << " destroyed!\n";
}

void	ClapTrap::attack( const std::string& target )
{
	if (m_hitPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " cannot attack because it is dead!\n";
		return ;
	}
	if (m_energyPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " cannot attack because it has no energy points left!\n";
		return ;
	}
	m_energyPoints--;
	std::cout << "ClapTrap " << m_name << " attacks " << target
		<< ", causing " << m_attackDamage << " points of damage!\n";
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (m_hitPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " is already dead!\n";
		return ;
	}
	if (amount >= m_hitPoints)
		m_hitPoints = 0;
	else
		m_hitPoints -= amount;
	std::cout << "ClapTrap " << m_name << " takes " << amount
		<< " points of damage! Remaining HP: " << m_hitPoints << "\n";
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (m_hitPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " cannot attack because it is dead!\n";
		return ;
	}
	if (m_energyPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " cannot attack because it has no energy points left!\n";
		return ;
	}
	m_energyPoints--;
	m_hitPoints += amount;
	std::cout << "ClapTrap " << m_name << " repairs itself for " << amount
		<< " hit points! Total HP: " << m_hitPoints << "\n";
}