/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 00:11:44 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/12 00:11:44 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << "FragTrap " << m_name << " enters the battlefield!\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << m_name << " copy constructed!\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << m_name << " has been decommissioned!\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (m_hitPoints == 0)
	{
		std::cout << "FragTrap " << m_name << " cannot high five because it is destroyed!\n";
		return;
    }
	std::cout << "FragTrap " << m_name << ": Hey guys, give me a positive high five! 🖐️\n";
}
