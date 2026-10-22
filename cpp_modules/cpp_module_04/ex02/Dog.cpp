/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:16:36 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:16:36 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	m_brain = new Brain();
	std::cout << "Dog default constructor called\n";
}

Dog::Dog( const Dog& other ) :
	AAnimal(other),
	m_brain(new Brain(*other.m_brain))
{
	std::cout << "Dog copy constructor called\n";
}

Dog&	Dog::operator=( const Dog& other )
{
	std::cout << "Dog assignment operator called\n";
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete m_brain;
		m_brain = new Brain(*other.m_brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete m_brain;
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!\n";
}

Brain*	Dog::getBrain() const
{
	return m_brain;
}
