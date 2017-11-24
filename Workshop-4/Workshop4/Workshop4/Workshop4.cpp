// Workshop4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>


void outputVector(std::vector<char>);

int main()
{
	//Part One

	////create the input file stream
	//char character;
	//std::ifstream input_stream;
	//std::vector<char> input_vector;


	////open the file stream
	//input_stream.open("Workshop4.cpp");

	////get the first character from the stream
	//input_stream.get(character);

	////loop through the file outputting each character
	//while (!input_stream.eof())
	//{
	//	input_vector.push_back(character);
	//	input_stream.get(character);
	//}

	////close the file stream 
	//input_stream.close();

	//outputVector(input_vector);

	//std::cout << std::endl;


	//Part Two
	std::srand((int)std::time(0));
	std::vector<int> iVector;
	std::vector<int>::iterator ivi;
	for(int x = 0; x < 100; x++)
	{
		//generates random number in range 0 - 1
		int i = std::rand() % 2;
		iVector.push_back(i);
	}

	//Heads count (0)
	int headsCount = 0;
	//Tails count (1)
	int tailsCount = 0;

	
	for (ivi = iVector.begin(); ivi != iVector.end(); ivi++) {
		if (*ivi == 0) {
			headsCount++;
		}
		else {
			tailsCount++;
		}

	}

	std::cout << "There are " << headsCount << " heads and " << tailsCount << " tails." << std::endl;

	int currentNumber = 0, currentTailsLength = 1, longestTailsLength = 1, currentHeadsLength = 1, longestHeadsLength = 1;
	for (ivi = iVector.begin(); ivi != iVector.end(); ivi++) {
		if (*ivi == 0 && *ivi == currentNumber) {
			currentHeadsLength++;
		}
		else if (*ivi == 1 && *ivi == currentNumber) {
			currentTailsLength++;
		}
		else {
			currentNumber = *ivi;

			if (currentHeadsLength > longestHeadsLength) {
				longestHeadsLength = currentHeadsLength;
			}
			if (currentTailsLength > longestTailsLength) {
				longestTailsLength = currentTailsLength;
			}

			currentHeadsLength = 1;
			currentTailsLength = 1;
		}

	}

	std::cout << "The longest sequence of heads is " << longestHeadsLength << " and the longest tails length is " << longestTailsLength << " ." << std::endl;

	return 0;
}

void outputVector(std::vector<char> vec)
{
	std::vector<char>::iterator it;
	it = vec.begin();
	for (it; it != vec.end();)
	{
		if (*it == '/') {

			while (*it != 10) {
				it++;
			}

		}
		else
		{
			std::cout << *it;
		}
		it++;

	}
}

