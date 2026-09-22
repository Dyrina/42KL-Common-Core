#include "File.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>\n";
		return 1;
	}

	File newFile(argv[1], argv[2], argv[3]);
	if (newFile.replaceFile() == false)
		return 1;

	return 0;
}