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
	std::cout << "------- 1. ANIMALS THROUGH BASE POINTERS -------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n------- 2. WRONG ANIMALS (NON-POLYMORPHIC) -------" << std::endl;
	std::cout << "Direct WrongCat: ";
	WrongCat wrongCat;
	wrongCat.makeSound();

	std::cout << "Through WrongAnimal pointer: ";
	const WrongAnimal* wrongMeta = new WrongCat();
	wrongMeta->makeSound();
	delete wrongMeta;

	return 0;
}
