#include <iostream>
#include <string>

int	main(void)
{
	std::string		brain("HI THIS IS BRAIN");
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "stringADR: " << &brain << "\n";
	std::cout << "stringPTR: " << &stringPTR << "\n";
	std::cout << "stringREF: " << &stringREF << "\n";

	std::cout << "stringADR: " << brain << "\n";
	std::cout << "stringPTR: " << *stringPTR << "\n";
	std::cout << "stringREF: " << stringREF << "\n";
}