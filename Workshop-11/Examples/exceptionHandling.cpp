/*
	CMP2090M OOP Lecture 11
	2017-2018 Academic Year
	Paul Baxter, UoL

	Basic exception handling example
*/

#include <iostream>

using namespace std;

int main()
{
	try
	{
		cout << "Inside try block" << endl;
		throw 1.0;
	}
	catch (double e)
	{
		cout << "Exception caught: " << e << endl;
	}
	catch (...)
	{
		cout << "Other exception caught!" << endl;
	}

	cout << "End" << endl;

	cout << endl;
	system("pause");
	return 0;
}
