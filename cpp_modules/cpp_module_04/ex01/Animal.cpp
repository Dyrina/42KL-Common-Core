/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:15:03 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:15:03 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() :
	type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal( const Animal& other ) :
	type(other.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal&	Animal::operator=( const Animal& other )
{
	std::cout << "Animal assignment operator called\n";
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

void Animal::makeSound() const
{
	std::cout << "* Generic animal sound *\n";
}

std::string Animal::getType() const
{
	return type;
}
