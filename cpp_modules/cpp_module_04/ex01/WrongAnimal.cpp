/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:25:23 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:25:23 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() :
	type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) :
	type(other.type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& other )
{
	std::cout << "WrongAnimal assignment operator called\n";
	if (this != &other)
		type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "* Generic wrong animal sound *\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}
