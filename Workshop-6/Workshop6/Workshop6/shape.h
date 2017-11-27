#pragma once

using namespace std;
class Shape {
private:
	float height;
	float width;
public:
	Shape();
	Shape(float, float);
	~Shape();
	float getHeight();
	float getWidth();
};

class Rectangle : public Shape{
public:
	Rectangle();
	Rectangle(float, float);
	bool calculateArea();
};

class Triangle : public Shape {
public:
	Triangle();
	Triangle(float, float);
	bool calculateArea();
};