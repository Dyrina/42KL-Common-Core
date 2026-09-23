/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:15:55 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 16:17:52 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void)
{
    std::cout << "[ WARNING ]\nI think I deserve some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}

void	Harl::error(void)
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    std::string levels[] =
    {
    	"DEBUG",
     	"INFO",
      	"WARNING",
       	"ERROR"
    };

    int i = 0;
	while (i < 4 && levels[i] != level) 
		++i;
	switch(i)
	{
		case 0:
			debug();
			// fallthrough
		case 1:
			info();
			// fallthrough
		case 2:
			warning();
			// fallthrough
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break ;
	}
}