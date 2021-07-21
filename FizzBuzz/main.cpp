#include <iostream>
#include <cstdlib> // std::atoi(const char*)

int main(int argc, char** argv)
{
	// Make sure enough parameters have been supplied
	if(argc != 2)
	{
		std::cerr << "Usage: FizzBuzz number" << std::endl;
		return 1;
	}

	int number = std::atoi(argv[1]);
	if(number < 1)
	{
		std::cerr << "Error: input number must be integer >= 1" << std::endl;
		return 2;
	}

	for(int index = 1; index <= number; index++)
	{
		if(index % 3 == 0 && index % 5 == 0)
		{
			std::cout << "FizzBuzz" << std::endl;
		}
		else if(index % 3 == 0)
		{
			std::cout << "Fizz" << std::endl;
		}
		else if(index % 5 == 0)
		{
			std::cout << "Buzz" << std::endl;
		}
		else
		{
			std::cout << index << std::endl;
		}
	}

	return 0;
}