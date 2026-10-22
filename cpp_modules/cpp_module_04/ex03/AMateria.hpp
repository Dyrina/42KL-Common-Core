/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:44:23 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:44:23 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria();
		AMateria( std::string const & type );
		AMateria( const AMateria& other );
		AMateria&	operator=( const AMateria& other );
		virtual	~AMateria();

		std::string const &	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use( ICharacter& target );
};

#endif
