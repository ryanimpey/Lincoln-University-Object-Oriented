#include "robot.h"
#include "ab.h"
#include <iostream>


using namespace std;

int main() {
	//don’t change any of the following
	B b;
	A *aP = &b;
	cout << aP->report() << endl; // want this to produce “I am child class”

	SocialRobot myrob("doug");


	int breakP = 0;
	cin >> breakP;
	return 0;

}