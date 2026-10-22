/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:49:59 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:49:59 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	std::cout << "------- 1. REQUIRED SUBJECT TEST -------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n------- 2. TYPES & CLONES -------" << std::endl;
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	std::cout << "created types: " << ice->getType() << ", " << cure->getType() << std::endl;
	AMateria* iceClone = ice->clone();
	std::cout << "clone type: " << iceClone->getType()
		<< " (different object: " << (iceClone != ice ? "yes" : "no") << ")" << std::endl;
	delete iceClone;
	delete ice;
	delete cure;

	std::cout << "\n------- 3. UNKNOWN TYPE -------" << std::endl;
	AMateria* unknown = src->createMateria("fire");
	std::cout << "createMateria(\"fire\"): "
		<< (unknown == NULL ? "NULL" : "unexpected materia") << std::endl;

	std::cout << "\n------- 4. INVALID OPERATIONS -------" << std::endl;
	me->use(-1, *bob);
	me->use(4, *bob);
	me->unequip(-1);
	me->unequip(4);
	me->equip(NULL);
	std::cout << "invalid calls were ignored, inventory intact:\n";
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n------- 5. FULL INVENTORY -------" << std::endl;
	Character full("full");
	full.equip(new Ice());
	full.equip(new Cure());
	full.equip(new Ice());
	full.equip(new Cure());
	AMateria* extraEquip = new Ice();
	full.equip(extraEquip);
	std::cout << "5th equip ignored, caller keeps: " << extraEquip->getType() << std::endl;
	delete extraEquip;

	std::cout << "\n------- 6. DUPLICATE EQUIP -------" << std::endl;
	AMateria* duplicated = new Cure();
	Character dupChar("dup");
	dupChar.equip(duplicated);
	dupChar.equip(duplicated);
	std::cout << "same pointer equipped only once:\n";
	dupChar.use(0, *bob);
	dupChar.use(1, *bob);

	std::cout << "\n------- 7. UNEQUIP (FLOOR) -------" << std::endl;
	AMateria* floor = src->createMateria("ice");
	me->equip(floor);
	me->unequip(2);
	delete floor;
	std::cout << "unequipped materia was deleted by the caller (no leak)\n";

	std::cout << "\n------- 8. CHARACTER DEEP COPY -------" << std::endl;
	AMateria* originalIce = src->createMateria("ice");
	Character original("original");
	original.equip(originalIce);
	original.equip(src->createMateria("cure"));

	Character copy(original);
	Character assigned("assigned");
	assigned = original;
	Character& assignedAlias = assigned;
	assigned = assignedAlias;

	std::cout << "copy uses its own materias:\n";
	copy.use(0, *bob);
	copy.use(1, *bob);
	std::cout << "assigned uses its own materias:\n";
	assigned.use(0, *bob);
	assigned.use(1, *bob);

	original.unequip(0);
	delete originalIce;
	std::cout << "original unequipped slot 0, copy still has it:\n";
	copy.use(0, *bob);

	std::cout << "\n------- 9. MATERIASOURCE COPY -------" << std::endl;
	MateriaSource localSrc;
	localSrc.learnMateria(new Ice());
	localSrc.learnMateria(new Cure());
	MateriaSource localCopy(localSrc);
	MateriaSource localAssigned;
	localAssigned = localSrc;

	AMateria* copiedIce = localCopy.createMateria("ice");
	AMateria* assignedCure = localAssigned.createMateria("cure");
	std::cout << "copied source types: " << copiedIce->getType()
		<< ", " << assignedCure->getType() << std::endl;
	delete copiedIce;
	delete assignedCure;

	std::cout << "\n------- 10. MATERIASOURCE FULL -------" << std::endl;
	localSrc.learnMateria(new Ice());
	localSrc.learnMateria(new Cure());
	AMateria* extraLearn = new Cure();
	localSrc.learnMateria(extraLearn);
	std::cout << "5th learn ignored, caller keeps: " << extraLearn->getType() << std::endl;
	delete extraLearn;

	std::cout << "\n------- 11. DELETIONS -------" << std::endl;
	delete bob;
	delete me;
	delete src;
	std::cout << "done" << std::endl;

	return 0;
}
