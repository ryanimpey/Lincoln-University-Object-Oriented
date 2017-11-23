// WorkshopOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "meanum.h"

int main(int argc, char* argv[])
{

	//argv[0] is always the filename of the program
	std::cout << "Number of arguments:" << argc << std::endl;

	if (argc == 4)
	{
		//'atoi' converts strings to their numerical values
		double number1 = atof(argv[1]);
		double number2 = atof(argv[3]);

		//char* needed as that is what argv[] is
		char* op = argv[2];


		//do the calculation based on what the operator is

		if (*op == '-')
		{
			std::cout << number1 << " - " << number2 << " = " << (number1 - number2) << std::endl;
		}
		else if (*op == '+')
		{
			std::cout << number1 << " + " << number2 << " = " << (number1 + number2) << std::endl;
		}
		else if (*op == '*')
		{
			std::cout << number1 << " * " << number2 << " = " << (number1 * number2) << std::endl;
		}
		else if (*op == '/')
		{
			std::cout << number1 << " / " << number2 << " = " << (number1 / number2) << std::endl;
		}
		else {
			std::cout << "Incorrect type of sum. -, +, *, and / are supported." << std::endl;
			return 0;
		}
	}
	else if (argc == 3)
	{
		std::string o;
		double num = atof(argv[2]);

		std::stringstream s = std::stringstream(argv[1]);
		s >> o;

		if (o == "sin")
		{
			std::cout << "sin " << num << " = " << sin(num) << std::endl;
		}
		else if (o == "cos") {
			std::cout << "cos" << num << " = " << cos(num) << std::endl;
		}
		else if (o == "tan") {
			std::cout << "cos" << num << " = " << cos(num) << std::endl;
		}
		else {
			std::cout << "Unsupported argument, sin, cos, and tan are supported" << std::endl;
		}

	}
	else {
		std::cout << "Incorrect amount of arguments" << std::endl;
		return 0;
	}


	std::cout << "Would you like to calculate the mean of a number? (Y/N)" << std::endl;
	char meanUserResponse;
	std::cin >> meanUserResponse;

	int meanValue = 0;

	if (meanUserResponse == 'Y' || meanUserResponse == 'y') {
		for (int i = 0; i < 10; i++) {
			std::cout << "Please enter a value:";
			double inputValue;
			std::cin >> inputValue;
			meanValue = meanNum(inputValue, meanValue);
		}

		std::cout << "Mean Value is " << meanValue / 10 << std::endl;
	}
	else {
		std::cout << "The program will now exit" << std::endl;
		return 0;
	}

	int num;
	std::cin >> num;
	return 0;
}