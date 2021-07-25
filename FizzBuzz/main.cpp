#include <iostream>	// cin, cout, cerr
#include <sstream> // stringstreams
#include <fstream> // ifstreams
#include <cstdlib>	// std::atoi(const char*)
#include <map>

// Lookup which string to return for a given input, if it must be mapped to a string
// @param fizzBuzzMap an ordered map of integers mapped to strings
// @param number the input number
// @return a string corresponding to the input number
std::string getFizzBuzzString(const std::map<int, std::string>& fizzBuzzMap, int number)
{
	std::string fizzBuzzString = "";
	
	// Compare this number with every integer in the map
	// This is much easier to read and maintain than using multiple if/else braches
	for(auto mapPair : fizzBuzzMap)
	{
		if(number % mapPair.first == 0) fizzBuzzString += mapPair.second;
	}

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

	// We can associate certain numbers with strings in a file, and read those file
	// contents into our map
	std::ifstream fizzBuzzFile("FizzBuzzMapping.txt");
	if(fizzBuzzFile.fail())
	{
		std::cerr << "Unable to open file \"FizzBuzzMapping.txt\"" << std::endl;
		return 3;
	}

	// Construct a mapping from integers to strings
	// Map is ordered, so we can add integer-string pairs in any order, and they'll 
	// be compared in numerical order (if order is not important, use 
	// std::unordered_map<int, std::string>)
	std::map<int, std::string> fizzBuzzMap;
	int mapNumber;
	std::string mapString;
	while(!fizzBuzzFile.eof())
	{
		fizzBuzzFile >> mapNumber >> mapString;
		fizzBuzzMap[mapNumber] = mapString;
	}

	// Process and output the strings
	std::ostringstream fizzBuzzString;
	for(int index = 1; index <= number; index++)
	{
		fizzBuzzString << getFizzBuzzString(fizzBuzzMap, index) << std::endl;
	}

	std::cout << fizzBuzzString.str();

	return 0;
}