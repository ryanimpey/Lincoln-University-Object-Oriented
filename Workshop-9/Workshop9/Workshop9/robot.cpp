#include "robot.h"
#include <iostream>

using namespace std;

Robot::Robot() {

}

Robot::Robot(string n) {

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

void SocialRobot::moveForward() {
	cout << "Social robot has moved forward!" << endl;
}

void SocialRobot::setName(string s) {
	robotName = s;
}

string SocialRobot::getName() {
	return robotName;
}

void IndustrialRobot::sayHello() {
	cout << "Hello, I am an industrial robot" << endl;
}