#define CATCH_CONFIG_MAIN
#include <catch_amalgamated.hpp>

#include <string>
#include "FizzBuzz.h"

TEST_CASE("FizzBuzz Functionality")
{
	FizzBuzz test;
	int initializationStatus = test.initialize("FizzBuzzMapping.txt");

	SECTION("Testing Initialization")
	{
		REQUIRE(initializationStatus == 1);
	}

	SECTION("Testing process(int)")
	{
		test.process(5);
		REQUIRE(test.toString() == "1\n2\nFizz\n4\nBuzz\n");
	}

	SECTION("Testing append(int)")
	{
		test.process(3);
		test.append(2);
		REQUIRE(test.toString() == "1\n2\nFizz\n4\nBuzz\n");
	}

	SECTION("Testing reset()")
	{
		test.process(5);
		test.reset();
		REQUIRE(test.toString() == "");
	}

	SECTION("Testing reset(int)")
	{
		test.process(5);
		bool resetStatus = test.reset(3);
		REQUIRE(test.toString() == "1\n2\nFizz\n");
		REQUIRE(resetStatus);
		test.append(2);
		REQUIRE(test.toString() == "1\n2\nFizz\n4\nBuzz\n");
	}

	SECTION("Testing reindex()")
	{
		test.process(5);
		bool reindexStatus = test.reindex(3);
		REQUIRE(reindexStatus);
		REQUIRE(test.toString() == "1\n2\nFizz\n");
		reindexStatus = test.reindex(6);
		REQUIRE(!reindexStatus);
		REQUIRE(test.toString() == "1\n2\nFizz\n");
		reindexStatus = test.reindex(5);
		REQUIRE(reindexStatus);
		REQUIRE(test.toString() == "1\n2\nFizz\n4\nBuzz\n");
	}
}

TEST_CASE("FizzBuzz Initialization Checking")
{
	FizzBuzz test;
	int initializationStatus1 = test.initialize("FuzzBizzMapping.txt");
	int initializationStatus2 = test.initialize("FizzBuzzMapping.txt");
	int initializationStatus3 = test.initialize("FizzBuzzMapping.txt");

	SECTION("Non-existant file")
	{
		REQUIRE(initializationStatus1 == -1);
	}

	SECTION("Proper initialization")
	{
		REQUIRE(initializationStatus2 == 1);
	}

	SECTION("Reinitialization attempt")
	{
		REQUIRE(initializationStatus3 == 0);
	}
}