#pragma once
#include <string>

class Circle{
public:
	Circle();
	Circle(float);
	~Circle();
	float radius;
};

class Square {
public:
	Square();
	Square(int);
	~Square();
	int side;
};

class Triangle {
public:
	Triangle();
	Triangle(double);
	~Triangle();
	double side;
};