// Workshop8.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "point.h"
#include <iostream>

int main()
{

	Point a(5, 5);
	Point b(5, 5);
	Point c = a+b;

	c.print();

	bool result = a == b;

	cout << result << endl;

	return 0;
}

