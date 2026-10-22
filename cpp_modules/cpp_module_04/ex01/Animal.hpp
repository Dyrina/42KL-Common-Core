/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:15:07 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:15:07 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal( const Animal& other );
		Animal&	operator=( const Animal& other );
		virtual	~Animal();

		virtual void	makeSound() const;
		std::string	getType() const;
};

#endif
