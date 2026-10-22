/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:49:30 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:49:30 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called\n";
	for (int i = 0; i < 4; i++)
		m_learned[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	std::cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if (other.m_learned[i])
			m_learned[i] = other.m_learned[i]->clone();
		else
			m_learned[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other )
{
	if (this != &other)
	{
		std::cout << "MateriaSource assignment operator called\n";
		for (int i = 0; i < 4; i++)
		{
			if (m_learned[i])
				delete m_learned[i];
			if (other.m_learned[i])
				m_learned[i] = other.m_learned[i]->clone();
			else
				m_learned[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called\n";
	for (int i = 0; i < 4; i++)
		delete m_learned[i];
}

void	MateriaSource::learnMateria( AMateria* m )
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (m_learned[i] == NULL)
		{
			m_learned[i] = m;
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < 4; i++)
	{
		if (m_learned[i] && m_learned[i]->getType() == type)
			return m_learned[i]->clone();
	}
	return NULL;
}
