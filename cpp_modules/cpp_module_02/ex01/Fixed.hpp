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
		int					toInt( void ) const;
		float				toFloat( void ) const;
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
};

std::ostream&	operator<<( std::ostream& oStream, const Fixed& fixedPoint);

#endif