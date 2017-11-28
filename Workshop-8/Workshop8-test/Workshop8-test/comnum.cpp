#include "stdafx.h"
#include "comnum.h"
#include <iostream>

using namespace std;

ComplexNumber::ComplexNumber() {
	a = 0.0;
	b = 0.0;
	cout << "Number created" << endl;
};

ComplexNumber::ComplexNumber(double da, double db) {
	a = da;
	b = db;
	cout << "Number created" << endl;
}

ComplexNumber::~ComplexNumber() {
	cout << "Number deleted" << endl;
}

void ComplexNumber::displayNum() {
	cout << a << "+" << b << "i" << endl;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber c) {
	ComplexNumber result;
	result.a = a + c.a;
	result.b = b + c.b;

	return result;
}