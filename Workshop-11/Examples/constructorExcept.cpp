/*
	CMP2090M OOP Lecture 11
	2017-2018 Academic Year
	Paul Baxter, UoL

	Constructor throwing exception example
*/

#include <iostream>
#include <string>

using namespace std;

class Ab
{
public:
	Ab()
	{
		cout << "Ab constructor..." << endl;
		string err = "error in Ab!";
		throw 1;
	}
	void print(void)
	{
		cout << "Hello, I am Ab" << endl;
	}
};

int mainConstruct()
{
	try
	{
		Ab ab;
		ab.print();
	}
	catch (string e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "Unhandled exception!" << endl;
	}
	
	cout << endl;
	system("pause");
	return 0;
}
