/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 14:55:13 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/08/22 14:55:13 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook	myBook;
	
	std::string userInput;
	std::cout << "Welcome to PhoneBook!\n";
	std::cout << "Available commands: ADD, SEARCH, EXIT\n";
	while (1)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, userInput))
		{
			std::cout << "\nExiting PhoneBook (EOF detected).\n";
			break;
		}
		if (userInput == "ADD")
			myBook.addContact();
		else if (userInput == "SEARCH")
			myBook.searchContacts();
		else if (userInput == "EXIT")
			break;
		else if (userInput == "")
			continue;
		else
			std::cout << "Invalid Command\n";
	}
    return (0);
}
