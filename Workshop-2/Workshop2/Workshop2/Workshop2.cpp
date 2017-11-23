// Workshop2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "isvalue.h"
#include "swaparr.h"
#include <iostream>

using namespace std;


int main()
{

	//Part One
	/*cout << "Please enter a single character: ";
	char input;
	cin >> std::noskipws >> input ;

	checkChar(input);*/

	//Part Two

	char c;
	char arr[10];
	char* arrPtr;
	arrPtr = arr;
	cout << "Enter some text" << endl;
	for(int x = 0; x < 5; x++)
	{
		std::cin >> c;
		*arrPtr = c;
		arrPtr++;
	}
	outputArray(arr, 5);

	cin >> c;
	return 0;
}

