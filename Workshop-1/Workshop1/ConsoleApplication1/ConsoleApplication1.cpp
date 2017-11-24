// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "calcs.h"
#include <string>

using namespace std;


int main(int argc, char* argv[])
{

	/*if (argc != 4) {
		cout << "Unsupported argument amount" << endl;
		return 0;
	}*/

	if (argc == 4){
		int iNumOne = atof(argv[1]);
		int iNumTwo = atof(argv[3]);

		cout << "Result: " << argumentType(argv[2], iNumOne, iNumTwo) << endl;
	}

	if (argc == 3) {
		string argVal(argv[1]);
		int iNum = atof(argv[2]);

		cout << "Result: " << smallArgumentType(argVal, iNum) << endl;
	}

	if (argc == 2) {
		string argVal(argv[1]);
		standardDev(argVal);
	}

	return 0;
}

