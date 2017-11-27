#include "point.h"
#include <iostream>

using namespace std;

int main(){
 
	Point a(5, 5);
	Point b(7, 7);
	Point c = a+b;

	c.print();

	return 1;
};