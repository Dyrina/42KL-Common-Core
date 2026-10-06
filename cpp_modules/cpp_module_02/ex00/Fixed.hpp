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

class	Fixed
{
	private:
		int					m_fixedPointNbr;
		static const int	m_fracBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed& other );
		Fixed&				operator=( const Fixed& other );
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
};

#endif