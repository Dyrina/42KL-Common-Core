/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:46:12 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:46:12 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure( const Cure& other );
		Cure&	operator=( const Cure& other );
		virtual	~Cure();

		virtual AMateria*	clone() const;
		virtual void		use( ICharacter& target );
};

#endif
