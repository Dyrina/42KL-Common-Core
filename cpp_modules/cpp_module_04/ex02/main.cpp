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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// AAnimal is abstract: these must not compile.
	// AAnimal meta;
	// AAnimal* heapMeta = new AAnimal();

	std::cout << "------- 1. ANIMALS THROUGH BASE POINTERS -------" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << "\nDeleting through AAnimal* (Brain must be freed):" << std::endl;
	delete j;
	delete i;

	std::cout << "\n------- 2. ARRAY OF ANIMALS -------" << std::endl;
	const int count = 4;
	const AAnimal* animals[count];

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
	Cat cat;
	cat.getBrain()->setIdea(0, "nap in the sun");
	std::cout << "cat's idea: " << cat.getBrain()->getIdea(0) << std::endl;

	return 0;
}
