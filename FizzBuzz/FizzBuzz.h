#pragma once

#include <vector>
#include <string>
#include <map>

/**
	A FizzBuzz objects holds a string representing a sequence of numbers or 
	words determined by a mapping. An index/bookmark is kept and tracked to 
	keep track of the processed string. The mapping is from integers to 
	strings, and the mapped strings are applied in sorted order based on their 
	associated integers. The numbers start at 1.
*/
class FizzBuzz
{
private:

	/* Data members */
	std::vector<std::string> fizzBuzzVector;	// The vector of strings
	std::map<int, std::string> fizzBuzzMap;	// The mapping from int to string
	int totalNumbersProcessed;	// The maximum processed integer number
	int index;	// The current number of processed numbers

	/* Function members */
	std::string getFizzBuzzString(int number);	// Get the string associated 
												// with the given number
public:
	/**
		Constructs a FizzBuzz with an empty vector and map
	*/
	FizzBuzz();

	/**
		Initializes the mapping to be used in constructing the FizzBuzz string
		@param filename the file from which to read the mapping information
		@return 1 if successful, 0 if already initialized, -1 on failure
	*/
	int initialize(std::string filename);

	/**
		Process the integers from 1 to the given number to form a FizzBuzz 
		string, and sets the location to be the end of the string to reflect 
		the total number of integers represented in the string. Doesn't do 
		anything if the current index/bookmark is already larger than the 
		given number.
		@param number the number of integers (from 1) to process
	*/
	void process(int number);

	/**
		Append the supplied number of integers to the end of the current 
		location in the FizzBuzz string, and sets the index accordingly
		@param number the number of integers to process past the current index 
	*/
	void append(int number);

	/**
		Moves the index/bookmark to the beginning of the string, and empties 
		the contents of the string
	*/
	void reset();

	/**
		Moves the index/bookmark to the specified location of the string, and 
		discards string contents past the index's location, but will not 
		advance the index/bookmark if the new location is past the largest 
		computed integer, or if a negative number is supplied
		@param location the place to move the index/bookmark
		@return true if index/bookmark is moved, false otherwise
	*/
	bool reset(int location);

	/**
		Moves the index/bookmark to the specified location of the string, but 
		will not discard string contents past the index/bookmark's new 
		location. Does not move the index/bookmark if the new location is past 
		the largest computed integer, or if a number less than one is supplied 
		@param location the place to move the index/bookmark
		@return true if the index/bookmark is moved, false otherwise
	*/
	bool reindex(int location);

	/**
		Gets the FizzBuzz string
		@return the FizzBuzz string
	*/
	std::string toString() const;
};