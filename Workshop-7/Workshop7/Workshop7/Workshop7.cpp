// Workshop7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void variableType(int a) {
	cout << "Variable is an int!" << endl;
}

void variableType(double a) {
	cout << "Variable is a double!" << endl;
}

void variableType(string a) {
	cout << "Variable is a string!" << endl;
}


bool howToSortDesc(int i, int j) {
	return i > j;
}

bool howToSortAsc(int i, int j) {
	return i < j;
}

bool howToSortDesc(int i, int j) {
	return i > j;
}

bool howToSortAsc(int i, int j) {
	return i < j;
}

void sortVector(vector<int> x, string str) {
	vector<int>::iterator xi;

	if (str == "asc") {
		sort(x.begin(), x.end(), howToSortAsc);
	}
	else {
		sort(x.begin(), x.end(), howToSortDesc);
	}
	
	for (xi = x.begin(); xi != x.end(); ++xi) {
		cout << *xi;
	}
	cout << endl;
}

void sortVector(vector<long> x, string str) {
	vector<long>::iterator xi;

	if (str == "asc") {
		sort(x.begin(), x.end(), howToSortAsc);
	}
	else {
		sort(x.begin(), x.end(), howToSortDesc);
	}

	for (xi = x.begin(); xi != x.end(); ++xi) {
		cout << *xi;
	}
	cout << endl;
}

void sortVector(vector<double> x, string str) {
	vector<double>::iterator xi;

	if (str == "asc") {
		sort(x.begin(), x.end(), howToSortAsc);
	}
	else {
		sort(x.begin(), x.end(), howToSortDesc);
	}

	for (xi = x.begin(); xi != x.end(); ++xi) {
		cout << *xi;
	}
	cout << endl;
}

int main()
{
	variableType(3);
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
	sortVector(myDoubleVec, "desc");
    return 0;
}
