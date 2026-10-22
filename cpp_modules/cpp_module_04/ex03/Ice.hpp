/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:45:09 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:45:09 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice( const Ice& other );
		Ice&	operator=( const Ice& other );
		virtual	~Ice();

		virtual AMateria*	clone() const;
		virtual void		use( ICharacter& target );
};

#endif
