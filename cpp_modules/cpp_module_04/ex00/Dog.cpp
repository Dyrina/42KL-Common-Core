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
	std::cout << "Dog default constructor called\n";
}

Dog::Dog( const Dog& other ) :
	Animal(other)
{
	std::cout << "Dog copy constructor called\n";
}

Dog&	Dog::operator=( const Dog& other )
{
	std::cout << "Dog assignment operator called\n";
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!\n";
}
