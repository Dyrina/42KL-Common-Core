/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:17:36 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:17:36 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	m_brain = new Brain();
	std::cout << "Cat default constructor called\n";
}

Cat::Cat( const Cat& other ) :
	Animal(other),
	m_brain(new Brain(*other.m_brain))
{
	std::cout << "Cat copy constructor called\n";
}

Cat&	Cat::operator=( const Cat& other )
{
	std::cout << "Cat assignment operator called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		delete m_brain;
		m_brain = new Brain(*other.m_brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete m_brain;
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!\n";
}

Brain*	Cat::getBrain() const
{
	return m_brain;
}
