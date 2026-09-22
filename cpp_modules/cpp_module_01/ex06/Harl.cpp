#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my burger!\n";
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\n";
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve some extra bacon for free.\n";
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager.\n";
}

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level)
{
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    int i = 0;
	while (i < 4 && levels[i] != level) {
		++i;
	}
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