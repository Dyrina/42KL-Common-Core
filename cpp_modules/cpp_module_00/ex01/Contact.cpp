/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:22:10 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/08/22 15:22:10 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static bool	getValidatedField(const std::string &prompt, std::string &dest)
{
	std::string	userInput;

	std::cout << prompt;
	std::getline(std::cin, userInput);
	if (userInput.empty() || userInput.find(' ') != std::string::npos)
		return (false);
	dest = userInput;
	return (true);
}

Contact::Contact() {}

bool	Contact::addDetails()
{
	return (getValidatedField("Enter First Name: ", m_firstname)
			&& getValidatedField("Enter Last Name: ", m_lastname)
			&& getValidatedField("Enter Nickname: ", m_nickname)
			&& getValidatedField("Enter Phone Number: ", m_phonenumber)
			&& getValidatedField("Enter Darkest Secret: ", m_darkestsecret));
}

std::string Contact::truncateString(const std::string& str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::displayRow(int index) const
{
	std::cout << "|" << std::setw(10) << index 
              << "|" << std::setw(10) << truncateString(m_firstname) 
              << "|" << std::setw(10) << truncateString(m_lastname) 
              << "|" << std::setw(10) << truncateString(m_nickname) 
              << "|\n";
}

void Contact::displayFullDetails() const {
    std::cout << "First Name: " << m_firstname << "\n";
    std::cout << "Last Name: " << m_lastname << "\n";
    std::cout << "Nickname: " << m_nickname << "\n";
    std::cout << "Phone Number: " << m_phonenumber << "\n";
    std::cout << "Darkest Secret: " << m_darkestsecret << "\n";
}
