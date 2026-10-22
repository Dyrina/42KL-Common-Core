/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:14:49 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:14:49 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "------- 1. ANIMALS THROUGH BASE POINTERS -------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << "\nDeleting through Animal* (Brain must be freed):" << std::endl;
	delete j;
	delete i;

	std::cout << "\n------- 2. ARRAY OF ANIMALS -------" << std::endl;
	const int count = 4;
	const Animal* animals[count];

	for (int k = 0; k < count; k++)
	{
		if (k % 2 == 0)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}

	for (int k = 0; k < count; k++)
	{
		std::cout << animals[k]->getType() << ": ";
		animals[k]->makeSound();
	}

	for (int k = 0; k < count; k++)
		delete animals[k];

	std::cout << "\n------- 3. BRAIN -------" << std::endl;
	Dog dog;
	dog.getBrain()->setIdea(0, "chase the ball");
	std::cout << "dog's idea: " << dog.getBrain()->getIdea(0) << std::endl;

	return 0;
}
