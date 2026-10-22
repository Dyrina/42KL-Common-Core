/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:35:32 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:35:32 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal( const AAnimal& other );
		AAnimal&	operator=( const AAnimal& other );
		virtual	~AAnimal();

		virtual void	makeSound() const = 0;
		std::string	getType() const;
};

#endif
