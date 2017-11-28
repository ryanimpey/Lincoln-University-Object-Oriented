#pragma once

using namespace std;

class ComplexNumber{
private:
	double a;
	double b;
public:
	ComplexNumber();
	ComplexNumber(double, double);
	~ComplexNumber();
	void displayNum();
	ComplexNumber operator+(const ComplexNumber);
};