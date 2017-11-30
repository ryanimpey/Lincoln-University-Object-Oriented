/*
	CMP2090M OOP Lecture 9
	2017-2018 Academic Year
	Paul Baxter, UoL

	Generic Classes, Inheritance, Virtual example
*/

#include <iostream>

using namespace std;


class BaseClass
{
public:
	virtual void print(void) = 0;
	//{
	//	cout << "Hello, I'm the BaseClass!" << endl;
	//}
};

class DerivedClass : public BaseClass
{
public:
	void print(void)
	{
		cout << "Hello, I'm the DerivedClass!" << endl;
	}
};

class SecondDerivedClass : public BaseClass
{
public:
	void print(void)
	{
		cout << "Hello, I'm a SecondDerivedClass!" << endl;
	}
};

void PrintOut(BaseClass&);


int mainGeneric(void)
{
	//BaseClass baseObject;	//can't do this because now abstract class!
	DerivedClass derivedObject;

	//the basic objects behave as expected
	//baseObject.print();
	derivedObject.print();

	cout << endl;

	//as does a pointer to a base object
	//BaseClass *b = &baseObject;
	BaseClass *b = &derivedObject;
	b->print();

	cout << endl;

	//a BaseClass pointer to a derived class object behaves differently...
	b = &derivedObject;
	b->print();
	PrintOut(*b);

	cout << endl;

	//why is this useful? because this:
	SecondDerivedClass secondObject;
	b = &secondObject;
	PrintOut(*b);
	//b = &baseObject;
	//PrintOut(*b);
	//which isn't very useful yet, but shows how you can write one general function to take in multiple types...
	// instead of separate functions for each type...

	//*b = baseObject;
	//b->print();

	cout << endl;
	system("pause");

	return 0;
}

void PrintOut(BaseClass &in)	//only want to take in BaseClass pointers...
{
	in.print();
	return;
}
