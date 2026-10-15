/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 23:03:54 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/11 23:03:54 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( const std::string newName );
		ScavTrap( const ScavTrap& other );
		ScavTrap&	operator=( const ScavTrap& other );
		~ScavTrap();
		void		attack( const std::string& target );
		void		guardGate();
};

#endif
