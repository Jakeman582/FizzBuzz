#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

#include "FizzBuzz.h"

std::string FizzBuzz::getFizzBuzzString(int number)
{
	std::string newString;
	for(auto mapping : fizzBuzzMap)
	{
		if(number % mapping.first == 0) newString += mapping.second;
	}
	if(newString == "") newString += std::to_string(number);
	return newString;
}

FizzBuzz::FizzBuzz()
{
	totalNumbersProcessed = 0;
	index = 0;
}

int FizzBuzz::initialize(std::string filename)
{
	// Don't reinitialize with a new map
	if(!fizzBuzzMap.empty()) return 0;

	// Let the caller know if the file failed to open
	std::ifstream mapFile(filename);
	if(mapFile.fail())
	{
		mapFile.close();
		return -1;
	}

	// Read the map file into the fizzBuzzMap
	while(!mapFile.eof())
	{
		int mapNumber;
		std::string mapString;
		mapFile >> mapNumber >> mapString;
		fizzBuzzMap[mapNumber] = mapString;
	}
	mapFile.close();
	return 1;
}

void FizzBuzz::process(int number)
{

	// Don't do anything if the given number is less than the current index
	if(number < index) return;

	// We can simply move the index/bookmark to the number given if the total 
	// number of integers processed is larger than the given number
	if(number <= totalNumbersProcessed)
	{
		index = number;
		return;
	}

	// At this point, there are additional numbers to process, but there is no 
	// need to process numbers already in the list
	for(index = totalNumbersProcessed; index < number; index++)
	{
		fizzBuzzVector.push_back(getFizzBuzzString(index));
	}
	totalNumbersProcessed = index;
}

void FizzBuzz::append(int number)
{
	// Do nothing if there are no numbers to append
	if(number < 1) return;

	// At this point, we need to increment the index using the processing 
	// from the process method
	process(number + index);

}

void FizzBuzz::reset()
{
	index = 0;
	totalNumbersProcessed;
	fizzBuzzVector.clear();
}

bool FizzBuzz::reset(int location)
{
	if(location < 1 || totalNumbersProcessed < location) return false;
	index = location;
	totalNumbersProcessed = location;
	fizzBuzzVector.erase(
		fizzBuzzVector.begin() + location, 
		fizzBuzzVector.end()
	);
}

bool FizzBuzz::reindex(int location)
{
	if(location < 1 || totalNumbersProcessed < location) return false;
	index = location;
	return true;
}

std::string FizzBuzz::toString() const
{
	std::ostringstream workingString;
	for(std::string current : fizzBuzzVector) workingString << current << std::endl;
	return workingString.str();
}