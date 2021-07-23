#include <iostream>	// cin, cout, cerr
#include <sstream> // stringstreams
#include <cstdlib>	// std::atoi(const char*)

std::string getFizzBuzzString(int number)
{
	std::string fizzBuzzString = "";
	if(number % 3 == 0) fizzBuzzString += "Fizz";
	if(number % 5 == 0) fizzBuzzString += "Buzz";

	if(fizzBuzzString == "") fizzBuzzString += std::to_string(number);

	return fizzBuzzString;
}

int main(int argc, char** argv)
{
	// Make sure enough parameters have been supplied
	if(argc != 2)
	{
		std::cerr << "Usage: FizzBuzz number" << std::endl;
		return 1;
	}

	// Make sure the input is large enough to produce results.
	int number = std::atoi(argv[1]);
	if(number < 1)
	{
		std::cerr << "Error: input number must be integer >= 1" << std::endl;
		return 2;
	}

	// Process and output the strings
	std::ostringstream fizzBuzzString;
	for(int index = 1; index <= number; index++)
	{
		fizzBuzzString << getFizzBuzzString(index) << std::endl;
	}

	std::cout << fizzBuzzString.str();

	return 0;
}