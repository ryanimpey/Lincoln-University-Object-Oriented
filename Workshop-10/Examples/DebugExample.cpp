/*
	CMP2090M OOP Lecture 10
	2017-2018 Academic Year
	Paul Baxter, UoL

	Workshop 9 debug example
*/

#include <iostream>
#include <string>

using namespace std;

class A
{
public:
	virtual string report(void) {
		return "I am parent class";
	}
}

class B : public A
{
public:
	string report(void) {
		return "I am child class";
	}
}

void main()
{
	//don't change any of the following
	B b;
	A *aP = &b;
	cout << aP->report() << endl; // want this to produce "I am child class"
	return 0;
}
