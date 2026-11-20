/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:02:42 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/11/10 23:02:42 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int	main(void)
{
	// Bureaucrat	Cat("Cat", 0);
	std::cout << "*----------------Construction Exception----------------*\n";
	try
	{
		Bureaucrat	Bob("Bob", 151);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Bureaucrat	Bob("Bob", 0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "*----------------Decrement & Increment----------------*\n";
	try
	{
		Bureaucrat	Bob("Luke", 150);
		for (short i = 0; i < 200; i++)
		{
			Bob.incrementGrade();
			std::cout << Bob;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	try	
	{
		Bureaucrat	John("John", 1);
		for (short i = 0; i < 200; i++)
		{
			John.decrementGrade();
			std::cout << John;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "*----------------Catch Block----------------*\n";
	std::cout << "*----------------Output Operator----------------*\n";
	return (0);
}