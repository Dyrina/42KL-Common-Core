/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:46:15 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:46:15 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() :
	AMateria("cure")
{
	std::cout << "Cure default constructor called\n";
}

Cure::Cure( const Cure& other ) :
	AMateria(other)
{
	std::cout << "Cure copy constructor called\n";
}

Cure&	Cure::operator=( const Cure& other )
{
	std::cout << "Cure assignment operator called\n";
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}

AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
