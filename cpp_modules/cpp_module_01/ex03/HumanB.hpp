/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:39:54 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 15:27:58 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string		name;
		const Weapon*	weapon;
	public:
		HumanB( const std::string newName );
		~HumanB();
		void			setWeapon( const Weapon& newWeapon );
		void			attack();
};

#endif