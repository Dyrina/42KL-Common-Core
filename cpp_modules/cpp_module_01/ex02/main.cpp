/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:23:06 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 15:23:03 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		brain("HI THIS IS BRAIN");
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "Memory address:\n";
	std::cout << "stringADR: " << &brain << "\n";
	std::cout << "stringPTR: " << &stringPTR << "\n";
	std::cout << "stringREF: " << &stringREF << "\n\n";

	std::cout << "Value:\n";
	std::cout << "stringADR: " << brain << "\n";
	std::cout << "stringPTR: " << *stringPTR << "\n";
	std::cout << "stringREF: " << stringREF << "\n";
}