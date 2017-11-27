#include "stdafx.h"
#include <string>
#include <iostream>
#include "shape.h"

using namespace std;

Shape::Shape() {
	height = 10;
	width = 10;
};

Shape::Shape(float h, float w) {
	height = h;
	width = w;
}

Shape::~Shape() {
	cout << "Shape deleted" << endl;
}

float Shape::getHeight() {
	return height;
}

float Shape::getWidth() {
	return width;
}

bool Rectangle::calculateArea() {
	float temph = getHeight();
	float tempw = getWidth();
	cout << "Rectangle area: " << temph * tempw << endl;
	return true;
}

bool Triangle::calculateArea() {
	float temph = getHeight();
	float tempw = getWidth();
	cout << "Rectangle area: " << (temph * tempw) / 2 << endl;
	return true;
}

Rectangle::Rectangle() :Shape() {
}

Rectangle::Rectangle(float h, float w) :Shape(h, w) {
	cout << "shape parameterised constructor called." << endl;
}

Triangle::Triangle() :Shape() {
}

Triangle::Triangle(float h, float w) : Shape(h, w) {
	cout << "shape parameterised constructor called" << endl;
}