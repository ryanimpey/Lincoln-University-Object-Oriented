// Workshop7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "message.h"
#include "shape.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <array>

using namespace std;

/* Part One //Bad Practice */
//void variableType(int a) {
//	cout << "Variable is an int!" << endl;
//}
//
//void variableType(double a) {
//	cout << "Variable is a double!" << endl;
//}
//
//void variableType(string a) {
//	cout << "Variable is a string!" << endl;
//}
//
//
//bool howToSortDesc(float i, float j) {
//	return i > j;
//}
//
//bool howToSortAsc(float i, float j) {
//	return i < j;
//}
//
//void sortVector(vector<int> x, string str) {
//	vector<int>::iterator xi;
//
//	if (str == "asc") {
//		sort(x.begin(), x.end(), howToSortAsc);
//	}
//	else {
//		sort(x.begin(), x.end(), howToSortDesc);
//	}
//	
//	for (xi = x.begin(); xi != x.end(); ++xi) {
//		cout << *xi << " ";
//	}
//	cout << endl;
//}
//
//void sortVector(vector<long> x, string str) {
//	vector<long>::iterator xi;
//
//	if (str == "asc") {
//		sort(x.begin(), x.end(), howToSortAsc);
//	}
//	else {
//		sort(x.begin(), x.end(), howToSortDesc);
//	}
//
//	for (xi = x.begin(); xi != x.end(); ++xi) {
//		cout << *xi << " ";
//	}
//	cout << endl;
//}
//
//void sortVector(vector<double> x, string str) {
//	vector<double>::iterator xi;
//
//	if (str == "asc") {
//		sort(x.begin(), x.end(), howToSortAsc);
//	}
//	else {
//		sort(x.begin(), x.end(), howToSortDesc);
//	}
//
//	for (xi = x.begin(); xi != x.end(); ++xi) {
//		cout << *xi << " ";
//	}
//	cout << endl;
//}

void area(float r) {
	const double pi = 3.1415926535897;
	float tempR = r * r;
	cout << "Area of a circle: " << pi * tempR << "." << endl;
};

void area(int s) {
	cout << "Area of a square: " << s * s << "." << endl;
}

void area(double s) {
	double topf = sqrt(3);
	double area = (topf / 4) * (s*s);

	cout << "Area of a (equilaterial) triangle: " << area << "." << endl;
}

int main()
{

	//Part One 
	/*variableType(3);
	variableType(2.5);
	variableType("string");

	vector<int> myIntVec = { 1,4,7,3,2 };
	vector<long> myLongVec = { 42,46,74,1,245 };
	vector<double> myDoubleVec = { 1.2,6.3,8.9,92.5 };
	sortVector(myIntVec, "asc");
	sortVector(myIntVec, "desc");
	sortVector(myLongVec, "asc");
	sortVector(myLongVec, "desc");
	sortVector(myDoubleVec, "asc");
	sortVector(myDoubleVec, "desc");*/

	//Part Two
	/*Message myMessage;
	myMessage.print();

	Message myOwnMessage("big message!");
	myMessage.print("hello world");*/

	//Part Three
	/*Circle myCircle(3);
	Square mySquare(5);
	Triangle myTriangle(3);

	area(myCircle.radius);
	area(mySquare.side);
	area(myTriangle.side);*/

	//Part Four
	cout << "How many videotapes are there?" << endl;
	int numVideotapes;
	cin >> numVideotapes;
	vector<string> videotapes(numVideotapes);
	vector<string>::iterator it;
	cout << "Enter the titles for each videotape." << endl;
	for (int x = 0; x != videotapes.size(); x++) {
		cout << x + 1 << ": ";
		cin >> videotapes.at(x);
	}
	cout << "==========" << endl;
	int temp = 1;
	for (it = videotapes.begin(); it != videotapes.end(); it++) {
		cout << temp << ". " << *it << endl;
		temp++;
	}

	vector<string> DVD = videotapes;
	for (it = DVD.begin(); it != DVD.end(); it++) {
		cout << *it << endl;
	}
    return 0;
}
