/*
	CMP2090M OOP Lecture 11
	2017-2018 Academic Year
	Paul Baxter, UoL

	Bad_typeid exception handling example
*/

#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
public:
	virtual void hello(void)
	{
		cout << "I am Base" << endl;
	}
};

class Derived : public Base
{
public:
	virtual void hello(void)
	{
		cout << "I am Derived from Base" << endl;
	}
};

int mainBad()
{
	Base *base = new Derived;

	Base *bPtr = 0;		//a null pointer

	try
	{
		cout << typeid(base).name() << endl;		//pointer not dereferenced?
		cout << typeid(*base).name() << endl;		//properly dereferenced, can access derived
		cout << typeid(*bPtr).name() << endl;		//null pointer!
	}
	catch (bad_typeid &e)
	{
		//reference in case want to pass the error on elsewhere, don't have to keep copying it...
		cout << "bad_typeid caught: " << e.what() << endl;
	}

	delete base;

	cout << endl;
	system("pause");
	return 0;
}
