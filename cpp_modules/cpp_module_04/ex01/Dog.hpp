/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:16:33 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:16:33 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	m_brain;
	public:
		Dog();
		Dog( const Dog& other );
		Dog&	operator=( const Dog& other );
		virtual	~Dog();

		virtual void	makeSound() const;
		Brain*			getBrain() const;
};

#endif
