/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:29:26 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:29:26 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain( const Brain& other )
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=( const Brain& other )
{
	std::cout << "Brain assignment operator called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

const std::string& Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	static const std::string empty = "";
	return empty;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}
