/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:44:44 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:44:44 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() :
	type("unknown")
{
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria( std::string const & type ) :
	type(type)
{
	std::cout << "AMateria parameterized constructor called\n";
}

AMateria::AMateria( const AMateria& other ) :
	type(other.type)
{
	std::cout << "AMateria copy constructor called\n";
}

AMateria&	AMateria::operator=( const AMateria& other )
{
	(void)other;
	std::cout << "AMateria assignment operator called\n";
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\n";
}

std::string const &	AMateria::getType() const
{
	return type;
}

void	AMateria::use( ICharacter& target )
{
	(void)target;
}
