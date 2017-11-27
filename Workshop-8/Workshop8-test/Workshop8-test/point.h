#pragma once

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point();
	Point(int, int);
	Point operator+(const Point &a);
	bool operator==(const Point &a);
	void print();

	//friend Point operator+(Point, Point);
};
