#include <iostream>

int main() 
{
	int	num = 1;

	for (int i = 0; i < 100; i++)
	{
		if (num % 15 == 0)
			std::cout << "FizzBuzz" << std::endl;
		else if (num % 3 == 0)
			std::cout << "Fizz" << std::endl;
		else if (num % 5 == 0)
			std::cout << "Buzz" << std::endl;
		else
			std::cout << num << std::endl;
		num++;
	}
}