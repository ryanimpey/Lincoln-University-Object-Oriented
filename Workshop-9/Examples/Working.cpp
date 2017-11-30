/*
	CMP2090M OOP Lecture 9
	2017-2018 Academic Year
	Paul Baxter, UoL

	Sample code using SampleClass
*/

#include <iostream>
#include <string>
#include "SampleClass.h"

using namespace std;

int main(int argc, char* argv[])
{
	SampleClass *s = new SampleClass;

	delete s;

	cout << endl;

	SampleDerived *d = new SampleDerived;

	delete d;

	cout << endl;

	SampleClass *newS = new SampleDerived;

	delete newS;

	cout << endl;
	system("pause");
	return 0;
}
