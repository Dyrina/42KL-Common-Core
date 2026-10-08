/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:36:23 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/04 15:36:23 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <ostream>
class	Fixed
{
	private:
		int					m_rawBits;
		static const int	m_fracBits = 8;
	public:
		Fixed();
		Fixed( const int newInt );
		Fixed( const float newFloat );
		~Fixed();
		Fixed( const Fixed& other );

		Fixed&				operator=( const Fixed& other );

		bool				operator>(const Fixed& other) const;
		bool				operator<(const Fixed& other) const;
		bool				operator>=(const Fixed& other) const;
		bool				operator<=(const Fixed& other) const;
		bool				operator==(const Fixed& other) const;
		bool				operator!=(const Fixed& other) const;

		Fixed				operator+(const Fixed& other) const;
		Fixed				operator-(const Fixed& other) const;
		Fixed				operator*(const Fixed& other) const;
		Fixed				operator/(const Fixed& other) const;

		Fixed&				operator++();
		Fixed&				operator--();
		Fixed				operator++(int);
		Fixed				operator--(int);

		static Fixed&       min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed&       max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		int					toInt( void ) const;
		float				toFloat( void ) const;
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
};

std::ostream&	operator<<( std::ostream& oStream, const Fixed& fixedPoint);

#endif