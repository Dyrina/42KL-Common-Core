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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "------- 1. REQUIRED SUBJECT TEST -------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nTypes:\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\nSounds:\n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\nDeletions:\n";
	delete meta;
	delete j;
	delete i;

	std::cout << "\n------- 2. DIRECT OBJECTS (NO POINTERS) -------" << std::endl;
	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << "\nTypes:\n";
	std::cout << animal.getType() << std::endl;
	std::cout << dog.getType() << std::endl;
	std::cout << cat.getType() << std::endl;

	std::cout << "\nSounds:\n";
	animal.makeSound();
	dog.makeSound();
	cat.makeSound();

	std::cout << "\n------- 3. COPY CONSTRUCTOR TESTS -------" << std::endl;
	Animal animalCopy(animal);
	Dog dogCopy(dog);
	Cat catCopy(cat);

	std::cout << "\nCopied types (must match the originals):\n";
	std::cout << animalCopy.getType() << std::endl;
	std::cout << dogCopy.getType() << std::endl;
	std::cout << catCopy.getType() << std::endl;

	std::cout << "\nCopied sounds:\n";
	animalCopy.makeSound();
	dogCopy.makeSound();
	catCopy.makeSound();

	std::cout << "\n------- 4. ASSIGNMENT OPERATOR TESTS -------" << std::endl;
	Animal animalAssign;
	Dog dogAssign;
	Cat catAssign;

	animalAssign = animal;
	dogAssign = dog;
	catAssign = cat;

	std::cout << "\nAssigned types (must match the originals):\n";
	std::cout << animalAssign.getType() << std::endl;
	std::cout << dogAssign.getType() << std::endl;
	std::cout << catAssign.getType() << std::endl;

	std::cout << "\nAssigned sounds:\n";
	animalAssign.makeSound();
	dogAssign.makeSound();
	catAssign.makeSound();

	std::cout << "\n------- 5. WRONG ANIMALS (NON-POLYMORPHIC) -------" << std::endl;
	std::cout << "\nDirect WrongCat call:\n";
	WrongCat wrongCatDirect;
	wrongCatDirect.makeSound();

	std::cout << "\nThrough WrongAnimal pointers (non-virtual -> generic sound):\n";
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "\nWrong copy constructor tests:\n";
	WrongAnimal wrongAnimalCopy(*wrongMeta);
	WrongCat wrongCatCopy(wrongCatDirect);

	std::cout << wrongAnimalCopy.getType() << std::endl;
	std::cout << wrongCatCopy.getType() << std::endl;
	wrongAnimalCopy.makeSound();
	wrongCatCopy.makeSound();

	std::cout << "\nDeletions:\n";
	delete wrongMeta;
	delete wrongCat;

	std::cout << "\n------- 6. ARRAY OF ANIMALS VIA BASE POINTERS -------" << std::endl;
	const int count = 6;
	const Animal* animals[count];

	for (int k = 0; k < count; k++)
	{
		if (k % 3 == 0)
			animals[k] = new Dog();
		else if (k % 3 == 1)
			animals[k] = new Cat();
		else
			animals[k] = new Animal();
	}

	std::cout << "\nTypes & sounds:\n";
	for (int k = 0; k < count; k++)
	{
		std::cout << animals[k]->getType() << ": ";
		animals[k]->makeSound();
	}

	std::cout << "\nDeleting through Animal* (virtual destructor):\n";
	for (int k = 0; k < count; k++)
		delete animals[k];

	std::cout << "\n------- 7. SCOPE & DESTRUCTION ORDER -------" << std::endl;
	{
		Cat scopeCat;
		Dog scopeDog;
		Animal scopeAnimal;
		std::cout << "Leaving scope (destructors run in reverse order)\n";
	}
	std::cout << "\nScope destroyed" << std::endl;

	return 0;
}
