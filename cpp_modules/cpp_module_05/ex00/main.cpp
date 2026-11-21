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
	std::cout << "*----------------Construction Exception----------------*\n";
	try
	{
		Bureaucrat	Baby("Bob", 151);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Bureaucrat	God("Bob", 0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "*----------------Decrement & Increment----------------*\n";
	try
	{
		Bureaucrat	Kiddo("Luke", 150);
		std::cout << Kiddo << "\n";
		for (short i = 0; i < 200; i++)
		{
			Kiddo.incrementGrade();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	try	
	{
		Bureaucrat	Boss("John", 1);
		std::cout << Boss << "\n";
		for (short i = 0; i < 200; i++)
		{
			Boss.decrementGrade();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	try	
	{
		Bureaucrat	Bucrat;
		std::cout << Bucrat << "\n";
		for (short i = 0; i < 200; i++)
		{
			Bucrat.decrementGrade();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "*----------------OCF & Output----------------*\n";
	try
	{
		Bureaucrat	Boss("Loud", 1);
		Bureaucrat	Senior("Soft", 2);
		Bureaucrat	Accomplice(Boss);
		std::cout << Boss << "\n";
		Boss = Senior;
		std::cout << Boss << "\n";
		std::cout << Accomplice << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}