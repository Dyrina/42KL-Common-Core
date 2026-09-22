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

void Harl::complain(std::string level) {
    // 1. Define a typedef for the member function pointer to keep syntax readable
    typedef void (Harl::*HarlMemFn)(void);

    // 2. Map levels to member function pointers
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    HarlMemFn functions[] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // 3. Search and dispatch
    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }

    std::cout << "[ Probably complaining about insignificant problems ]\n";
}