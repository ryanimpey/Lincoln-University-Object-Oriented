#include "robot.h"
#include <iostream>

using namespace std;

Robot::Robot() {
	robotName = "Generic";
}

Robot::Robot(string n) {
	robotName = n;
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

SocialRobot::SocialRobot(string s) : Robot(s) {
	//Hmm
}

IndustrialRobot::IndustrialRobot(string s) : Robot(s) {
	//Hmm
}

void SocialRobot::sayHello() {
	cout << "Hello, I am a social robot" << endl;
}

void IndustrialRobot::sayHello() {
	cout << "Hello, I am an industrial robot" << endl;
}