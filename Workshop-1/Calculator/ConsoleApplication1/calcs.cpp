#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

float argumentType(char* cChar, int a, int b) {
	if (*cChar == '*') {
		return a *(float) b;
	}
	else if (*cChar == '/') {
		return a / (float)b;
	}
	else if (*cChar == '+') {
		return a + (float)b;
	}
	else if (*cChar == '-') {
		return a - (float)b;
	}
	else {
		std::cout << "Unsupported symbol." << std::endl;
		return 0;
	}
}

float smallArgumentType(std::string str, int a) {
	if (str == "sin") {
		return std::sin(a);
	}
	else if (str == "cos") {
		return std::cos(a);
	}
	else if (str == "tan") {
		return std::tan(a);
	}
	else {
		std::cout << "Unsupported input" << std::endl;
		return 0;
	}
}

float standardDev(std::string str) {
	if (str != "mean") {
		std::cout << "Not supported" << std::endl;
		return 0;
	}
	else {
		std::cout << "Please enter your 10 values." << std::endl;
		int count = 1;
		std::vector<int> iVector;
		std::vector<int>::iterator iVit;
		float meanValue = 0;
		float standardDev = 0;

		while (count < 11) {
			std::cout << "Please enter value " << count << ": ";
			int temp;
			std::cin >> temp;
			iVector.push_back(temp);
			count++;
		}
		for (iVit = iVector.begin(); iVit != iVector.end(); ++iVit) {
			meanValue += *iVit;
		}
		meanValue /= 10;
		std::cout << "Your mean value is: " << meanValue << std::endl;

		for (iVit = iVector.begin(); iVit != iVector.end(); ++iVit) {
			*iVit -= meanValue;
			float temp = *iVit;
			*iVit = temp * temp;
			standardDev += *iVit;
		}

		standardDev /= 10;

		std::cout << "Your standard deviation is: " << standardDev << std::endl;
	}
}