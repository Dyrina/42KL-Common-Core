/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:48:32 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:48:32 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() :
	m_name("default")
{
	std::cout << "Character default constructor called\n";
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character( std::string const & name ) :
	m_name(name)
{
	std::cout << "Character constructor called for " << m_name << "\n";
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character( const Character& other ) :
	m_name(other.m_name)
{
	std::cout << "Character copy constructor called for " << m_name << "\n";
	for (int i = 0; i < 4; i++)
	{
		if (other.m_inventory[i])
			m_inventory[i] = other.m_inventory[i]->clone();
		else
			m_inventory[i] = NULL;
	}
}

Character&	Character::operator=( const Character& other )
{
	if (this != &other)
	{
		std::cout << "Character assignment operator called\n";
		m_name = other.m_name;
		for (int i = 0; i < 4; i++)
		{
			if (m_inventory[i])
				delete m_inventory[i];
			if (other.m_inventory[i])
				m_inventory[i] = other.m_inventory[i]->clone();
			else
				m_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called for " << m_name << "\n";
	for (int i = 0; i < 4; i++)
		delete m_inventory[i];
}

std::string const &	Character::getName() const
{
	return m_name;
}

void	Character::equip( AMateria* m )
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] == m)
			return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] == NULL)
		{
			m_inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip( int idx )
{
	if (idx < 0 || idx >= 4)
		return;
	m_inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < 4 && m_inventory[idx])
		m_inventory[idx]->use(target);
}
