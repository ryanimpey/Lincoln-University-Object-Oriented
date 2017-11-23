// workshop3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> a = { 1,3,5,7,9 };
	std::vector<int> b = { 0, 2,4,6,8,10 };
	std::vector<int> newVector;

	std::vector<int>::iterator ai = a.begin();
	std::vector<int>::iterator bi = b.begin();
	std::vector<int>::iterator newi;

	// Part One
	/*std::reverse(iVector.begin(), iVector.end());

	for (ivi = iVector.begin(); ivi != iVector.end(); ++ivi) {
		std::cout << *ivi << std::endl;
	}*/

	// Part Two
/*
	int counter = 0;
	for (ivi = iVector.begin(); ivi != iVector.end();) {
		if (*ivi % 2 != 0) {
			ivi = iVector.erase(ivi);
		}
		ivi++;
	}

	for (ivi = iVector.begin(); ivi != iVector.end(); ++ivi) {
		std::cout << *ivi << std::endl;
	}*/

	// Part Three
	while (ai != a.end() && bi != b.end()) {
		newVector.push_back(*bi);
		newVector.push_back(*ai);
		ai++;
		bi++;
	}

	if (ai != a.end()) {
		while (ai != a.end()) {
			newVector.push_back(*ai);
			ai++;
		}
	}

	if (bi != b.end()) {
		while (bi != b.end()) {
			newVector.push_back(*bi);
			bi++;
		}
	}

	for (newi = newVector.begin(); newi != newVector.end(); ++newi) {
		cout << *newi << endl;
	}

    return 0;
}

