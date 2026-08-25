/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:22:05 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/08/22 15:22:05 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : m_currentIndex(0), m_totalContacts(0) {}

void	PhoneBook::addContact()
{
	Contact	newContact;

	if (newContact.addDetails() == false)
	{
		std::cout << "Error: no whitespaces or empty field\n";
		return;
	}
	m_contacts[m_currentIndex] = newContact;
	m_currentIndex = (m_currentIndex + 1) % MAX_CONTACTS;
	if (m_totalContacts < MAX_CONTACTS)
		m_totalContacts++;
	std::cout << "Contact added successfully!\n";
}

void	PhoneBook::displayTable() const
{
	int	start;
	int	k;

	if (m_totalContacts < MAX_CONTACTS)
	    start = 0;
	else
        start = m_currentIndex;
	std::cout << "---------------------------------------------\n";
	std::cout << "|" << std::setw(10) << "Index"
	          << "|" << std::setw(10) << "First Name"
	          << "|" << std::setw(10) << "Last Name"
	          << "|" << std::setw(10) << "Nickname"
	          << "|\n";
	std::cout << "---------------------------------------------\n";
	for (k = 0; k < m_totalContacts; ++k)
		m_contacts[(start + k) % MAX_CONTACTS].displayRow(k);
	if (m_totalContacts == 0)
		std::cout << "|" << std::setw(45) << "|\n";
	std::cout << "---------------------------------------------\n";
}

void	PhoneBook::searchContacts()
{
	std::string	userInput;
	int			index;
	int			start;

	displayTable();
	std::cout << "Enter index: ";
	std::getline(std::cin, userInput);
	if (userInput.length() != 1 || userInput[0] < '0' || userInput[0] > '7')
	{
		std::cout << "Error: Invalid index. Must be a single digit between 0 and 7.\n";
		return;
	}
	index = userInput[0] - '0';
	if (index >= m_totalContacts)
	{
		std::cout << "Error: No contact exists at that index yet.\n";
		return;
	}
	if (m_totalContacts < MAX_CONTACTS)
		start = 0;
	else
		start = m_currentIndex;
	m_contacts[(start + index) % MAX_CONTACTS].displayFullDetails();
}
