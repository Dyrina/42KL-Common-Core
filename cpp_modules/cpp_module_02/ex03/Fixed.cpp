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
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() :
	m_rawBits(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed( const int newInt )
{
	// std::cout << "Int constructor called\n";
	m_rawBits = newInt << m_fracBits;
}

Fixed::Fixed( const float newFloat )
{
	// std::cout << "Float constructor called\n";
	m_rawBits = roundf(newFloat * (1 << m_fracBits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

Fixed::Fixed( const Fixed& other )
{
	// std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed&	Fixed::operator=( const Fixed& other )
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &other)
		m_rawBits = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
    return m_rawBits > other.m_rawBits;
}

bool Fixed::operator<(const Fixed& other) const
{
    return m_rawBits < other.m_rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return m_rawBits >= other.m_rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return m_rawBits <= other.m_rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
    return m_rawBits == other.m_rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return m_rawBits != other.m_rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(m_rawBits + other.m_rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(m_rawBits - other.m_rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long temp = ((long)m_rawBits * (long)other.m_rawBits) >> m_fracBits;
    result.setRawBits((int)temp);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long temp = ((long)m_rawBits << m_fracBits) / other.m_rawBits;
    result.setRawBits((int)temp);
    return result;
}

Fixed& Fixed::operator++()
{
    m_rawBits += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    m_rawBits += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    m_rawBits -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    m_rawBits -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called\n";
	return m_rawBits;
}

void	Fixed::setRawBits( const int raw )
{
	// std::cout << "setRawBits member function called\n";
	m_rawBits = raw;
}

int	Fixed::toInt() const
{
	return m_rawBits >> m_fracBits;
}

float	Fixed::toFloat() const
{
	return (float) m_rawBits / (1 << m_fracBits);
}

std::ostream&	operator<<( std::ostream& oStream, const Fixed& fixedPoint)
{
	oStream << fixedPoint.toFloat();
	return oStream;
}
