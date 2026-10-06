/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:36:27 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/04 15:36:27 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() :
	m_fixedPointNbr(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed&	Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		m_fixedPointNbr = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return m_fixedPointNbr;
}

void	Fixed::setRawBits( const int raw )
{
	std::cout << "setRawBits member function called\n";
	m_fixedPointNbr = raw;
}
