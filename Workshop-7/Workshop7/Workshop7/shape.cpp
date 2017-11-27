#include "stdafx.h"
#include "shape.h"
#include <iostream>

using namespace std;

Circle::Circle() {
	radius = 1.0;
}

Circle::Circle(float r) {
	radius = r;
}

Circle::~Circle() {
	cout << "Circle destroyed" << endl;
}

Square::Square() {
	side = 5;
}

Square::Square(int s) {
	side = s;
}

Square::~Square() {
	cout << "Square destroyed" << endl;
}

Triangle::Triangle() {
	side = 90;
}

Triangle::Triangle(double a) {
	side = a;
}

Triangle::~Triangle() {
	cout << "Triangle Destroyed" << endl;
}