/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:48:10 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:48:10 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	m_name;
		AMateria*	m_inventory[4];
	public:
		Character();
		Character( std::string const & name );
		Character( const Character& other );
		Character&	operator=( const Character& other );
		virtual	~Character();

		virtual std::string const &	getName() const;
		virtual void	equip( AMateria* m );
		virtual void	unequip( int idx );
		virtual void	use( int idx, ICharacter& target );
};

#endif
