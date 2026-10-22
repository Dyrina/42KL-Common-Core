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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	// Both of these must fail to compile: AAnimal is abstract.
	// AAnimal meta;
	// AAnimal* heapMeta = new AAnimal();

	std::cout << "------- 1. REQUIRED SUBJECT TEST -------" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << "\nDeletions (Brain must be freed):\n";
	delete j;
	delete i;

	std::cout << "\n------- 2. ARRAY OF ANIMALS VIA BASE POINTERS -------" << std::endl;
	const int count = 6;
	AAnimal* animals[count];

	for (int k = 0; k < count; k++)
	{
		if (k % 2 == 0)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}

	std::cout << "\nTypes & sounds:\n";
	for (int k = 0; k < count; k++)
	{
		std::cout << animals[k]->getType() << ": ";
		animals[k]->makeSound();
	}

	std::cout << "\nDeleting through AAnimal* (virtual destructor):\n";
	for (int k = 0; k < count; k++)
		delete animals[k];

	std::cout << "\n------- 3. DEEP COPY CONSTRUCTOR (DOG) -------" << std::endl;
	Dog dog;
	dog.getBrain()->setIdea(0, "chase the ball");
	dog.getBrain()->setIdea(1, "guard the house");

	std::cout << "\nCopying dog...\n";
	Dog dogCopy(dog);

	std::cout << "\nCopy idea 0: " << dogCopy.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea 1: " << dogCopy.getBrain()->getIdea(1) << std::endl;
	std::cout << "Brain pointers differ: "
		<< (dog.getBrain() != dogCopy.getBrain() ? "yes" : "no") << std::endl;

	dog.getBrain()->setIdea(0, "sleep all day");
	std::cout << "\nAfter mutating the original:\n";
	std::cout << "original idea 0: " << dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "copy idea 0:     " << dogCopy.getBrain()->getIdea(0) << std::endl;
	std::cout << (dog.getBrain()->getIdea(0) != dogCopy.getBrain()->getIdea(0)
		? "DEEP COPY OK" : "SHALLOW COPY DETECTED") << std::endl;

	std::cout << "\n=== 4. DEEP COPY CONSTRUCTOR (CAT) ===" << std::endl;
	Cat cat;
	cat.getBrain()->setIdea(0, "knock things off the table");
	cat.getBrain()->setIdea(1, "nap in the sun");

	std::cout << "\nCopying cat...\n";
	Cat catCopy(cat);

	std::cout << "\nCopy idea 0: " << catCopy.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea 1: " << catCopy.getBrain()->getIdea(1) << std::endl;
	std::cout << "Brain pointers differ: "
		<< (cat.getBrain() != catCopy.getBrain() ? "yes" : "no") << std::endl;

	cat.getBrain()->setIdea(0, "ignore everyone");
	std::cout << "\nAfter mutating the original:\n";
	std::cout << "original idea 0: " << cat.getBrain()->getIdea(0) << std::endl;
	std::cout << "copy idea 0:     " << catCopy.getBrain()->getIdea(0) << std::endl;
	std::cout << (cat.getBrain()->getIdea(0) != catCopy.getBrain()->getIdea(0)
		? "DEEP COPY OK" : "SHALLOW COPY DETECTED") << std::endl;

	std::cout << "\n------- 5. DEEP COPY ASSIGNMENT (DOG) -------" << std::endl;
	Dog dogA;
	Dog dogB;
	dogA.getBrain()->setIdea(0, "dog A idea");
	dogB.getBrain()->setIdea(0, "dog B old idea");

	std::cout << "B before assignment: " << dogB.getBrain()->getIdea(0) << std::endl;
	dogB = dogA;
	std::cout << "B after assignment:  " << dogB.getBrain()->getIdea(0) << std::endl;
	std::cout << "Brain pointers differ: "
		<< (dogA.getBrain() != dogB.getBrain() ? "yes" : "no") << std::endl;

	dogA.getBrain()->setIdea(0, "dog A changed");
	std::cout << "A after mutation:    " << dogA.getBrain()->getIdea(0) << std::endl;
	std::cout << "B after mutation:    " << dogB.getBrain()->getIdea(0) << std::endl;
	std::cout << (dogA.getBrain()->getIdea(0) != dogB.getBrain()->getIdea(0)
		? "DEEP ASSIGNMENT OK" : "SHALLOW ASSIGNMENT DETECTED") << std::endl;

	Dog& dogAlias = dogA;
	dogA = dogAlias;
	std::cout << "Self-assignment keeps idea: " << dogA.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n------- 6. DEEP COPY ASSIGNMENT (CAT) -------" << std::endl;
	Cat catA;
	Cat catB;
	catA.getBrain()->setIdea(0, "cat A idea");
	catB.getBrain()->setIdea(0, "cat B old idea");

	std::cout << "B before assignment: " << catB.getBrain()->getIdea(0) << std::endl;
	catB = catA;
	std::cout << "B after assignment:  " << catB.getBrain()->getIdea(0) << std::endl;
	std::cout << "Brain pointers differ: "
		<< (catA.getBrain() != catB.getBrain() ? "yes" : "no") << std::endl;

	catA.getBrain()->setIdea(0, "cat A changed");
	std::cout << "A after mutation:    " << catA.getBrain()->getIdea(0) << std::endl;
	std::cout << "B after mutation:    " << catB.getBrain()->getIdea(0) << std::endl;
	std::cout << (catA.getBrain()->getIdea(0) != catB.getBrain()->getIdea(0)
		? "DEEP ASSIGNMENT OK" : "SHALLOW ASSIGNMENT DETECTED") << std::endl;

	Cat& catAlias = catA;
	catA = catAlias;
	std::cout << "Self-assignment keeps idea: " << catA.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n------- 7. WRONG ANIMALS (NON-POLYMORPHIC) -------" << std::endl;
	WrongCat wrongCat;
	WrongAnimal wrongAnimal;
	WrongAnimal* wrongPtr = &wrongCat;

	std::cout << "wrongAnimal direct:    ";
	wrongAnimal.makeSound();
	std::cout << "wrongCat direct:       ";
	wrongCat.makeSound();
	std::cout << "wrongCat via base ptr: ";
	wrongPtr->makeSound();

	std::cout << "\nCopy tests:\n";
	WrongCat wrongCatCopy(wrongCat);
	WrongAnimal wrongAnimalCopy(wrongAnimal);
	std::cout << wrongCatCopy.getType() << ": ";
	wrongCatCopy.makeSound();
	std::cout << wrongAnimalCopy.getType() << ": ";
	wrongAnimalCopy.makeSound();

	std::cout << "\nDeleting wrong animals through base pointers:\n";
	const WrongAnimal* heapWrongAnimal = new WrongAnimal();
	const WrongAnimal* heapWrongCat = new WrongCat();
	delete heapWrongAnimal;
	delete heapWrongCat;

	std::cout << "\n------- 8. SCOPE & DESTRUCTION ORDER -------" << std::endl;
	{
		Dog scopeDog;
		Cat scopeCat;
		std::cout << "Leaving scope: Brain, then Dog/Cat, then AAnimal\n";
	}
	std::cout << "Scope destroyed" << std::endl;

	std::cout << "\n------- 9. END OF MAIN -------" << std::endl;
	return 0;
}
