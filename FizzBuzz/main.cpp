#include <iostream>

int main()
{
	int number = 100;

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