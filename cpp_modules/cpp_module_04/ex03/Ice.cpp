/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:45:32 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:45:32 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() :
	AMateria("ice")
{
	std::cout << "Ice default constructor called\n";
}

Ice::Ice( const Ice& other ) :
	AMateria(other)
{
	std::cout << "Ice copy constructor called\n";
}

Ice&	Ice::operator=( const Ice& other )
{
	std::cout << "Ice assignment operator called\n";
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}

AMateria*	Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
