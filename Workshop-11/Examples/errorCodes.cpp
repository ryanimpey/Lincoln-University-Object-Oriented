/*
	CMP2090M OOP Lecture 11
	2017-2018 Academic Year
	Paul Baxter, UoL

	Error codes from functions example
*/

#include <iostream>

using namespace std;


enum ReturnType
{
	SUCCESS = 0,
	ERROR_LOW = 1,
	ERROR_HIGH = 2
};


bool functionBool (int input)
{
	if ((input - 2) < 0)
	{
		cout << "functionBool raising error" << endl;
		return true;
	}

	cout << "functionBool completed correctly" << endl;
	return false;
}

int functionInt(int input)
{
	if (input < 0)
	{
		cout << "too low..." << endl;
		return ERROR_LOW;
	}
	else if (input > 10)
	{
		cout << "too high..." << endl;
		return ERROR_HIGH;
	}
	//otherwise carry on...
	return SUCCESS;
}


int mainCodes()
{
	int err = functionInt(11);

	if (err == ERROR_HIGH)
	{
		//
	}

	cout << endl;
	system("pause");
	return 0;
}
