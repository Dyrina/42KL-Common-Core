/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:20:45 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:20:45 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat( const WrongCat& other ) :
	WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	std::cout << "WrongCat assignment operator called\n";
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat Meow!\n";
}
