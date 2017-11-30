#include "robot.h"
#include <iostream>

using namespace std;

Robot::Robot() {
	robotName = "Generic";
}

Robot::Robot(string n) {
	robotName = n;
}

void Robot::sayHello() {
	cout << "Hello, I am a basic robot." << endl;
}

void Robot::moveForward() {
	cout << robotName + " robot moving forward...";
	cout << " ... finished" << endl;
}

void Robot::setName(string n) {
	robotName = n;
}

string Robot::getName() {
	return robotName;
}