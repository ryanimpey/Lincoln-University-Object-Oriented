#include "stdafx.h"
#include "point.h"
#include <iostream>
#include <string>

using namespace std;

Point::Point() {
	x = 0;
	y = 0;
};

Point::Point(int xval, int yval) {
	x = xval;
	y = yval;
};

Point Point::operator+(const Point &a) {

	Point result;

	result.x = x + a.x;

	result.y = y + a.y;

	return result;
}

bool Point::operator==(const Point &a) {
	if (x == a.x && y == a.y) {
		return true;
	}
	else {
		return false;
	}
}

void Point::print() {
	cout << x << " " << y << endl;
}

/* Friend*/
//Point operator+(Point a, Point b) {
//	Point result;
//
//	result.x = a.x + b.x;
//}