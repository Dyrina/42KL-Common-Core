/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:35:35 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:35:35 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() :
	type("AAnimal")
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal( const AAnimal& other ) :
	type(other.type)
{
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal&	AAnimal::operator=( const AAnimal& other )
{
	std::cout << "AAnimal assignment operator called\n";
	if (this != &other)
		type = other.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

std::string AAnimal::getType() const
{
	return type;
}
