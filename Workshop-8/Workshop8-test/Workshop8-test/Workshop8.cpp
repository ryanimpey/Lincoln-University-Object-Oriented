// Workshop8.cpp : Defines the entry point for the console application.
//
#include "point.h"
#include "comnum.h"
#include "time.h"
#include "matrix.h"
#include <iostream>
#include <ctime>
#include <string>

int main()
{
	//Part One
/*
	Point a(5, 7);
	Point b(6, 7);
	Point c = a+b;

	c.print();

	bool result = a == b;
	if (result) {
		cout << "A is equal to B!" << endl;
	}
	else {
		cout << "A is not equal to B!" << endl;
	}*/

	////Part Two
	//ComplexNumber a(5.2, 6.4);
	//ComplexNumber b(4.8, 3.6);
	//a.displayNum();
	//b.displayNum();

	//ComplexNumber c;

	//c = a + b;

	//c.displayNum();

	////Part Three
	//Time a(5, 30, 30);
	//Time b(4, 15, 14);

	//Time c;

	//c = a + b;
	//c.printTime();


	//Part Three
	Matrix a(3, 4, 1);

	cout << a;

	return 0;
}

