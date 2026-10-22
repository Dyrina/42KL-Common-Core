/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:17:33 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:17:33 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	m_brain;
	public:
		Cat();
		Cat( const Cat& other );
		Cat&	operator=( const Cat& other );
		virtual	~Cat();

		virtual void	makeSound() const;
		Brain*			getBrain() const;
};

#endif
