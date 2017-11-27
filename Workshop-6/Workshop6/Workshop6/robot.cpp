#include "stdafx.h"
#include <string>
#include <iostream>
#include "Robot.h"

using namespace std;

float Robot::getPosition() {
	return position;
}

bool Robot::forward(float m) {
	if (length != 0.0f) {
		position += length * m;
		cout << "moving robot " << name << "!" << endl;
		return true;
	}
	else
		return false;
}

void Robot::info() {
	cout << "Robot " << name << " has length " << length << " and position " << position << " and angle " << angle << '\370' << endl;
}

bool Robot::turn(int a) {
	if (a % 90 != 0) {
		cout << "Cannot turn robot " << name << ", only angles allowed are 90\370 180\370 270\370 360\370" << endl;
		return false;
	}
	else {
		if (angle + a > 360) {
			angle = (angle + a) - 360;
		}
		else {
			angle += a;
		}

		return true;
	}

}

Robot::Robot()
{
	name = "default";
	length = 0.0f;
	position = 0.0f;
	angle = 0;
	cout << "Constructor invoked" << endl;
}

Robot::Robot(string n, float l)
{
	cout << "Constructor invoked" << endl;
	name = n;
	length = l;
	position = 0.0f;
	angle = 0;
}

Robot::~Robot()
{
	cout << "destructor invoked. " << endl;
}

void AutonomousCar::setCarName(string str){
	name = str;
	cout << "The new name of this car is " << name << "!" << endl;
}

bool AutonomousCar::turn() {
	cout << "An autonomous car cannot move on the spot, sorry!" << endl;
	return false;
}

void AutonomousCar::driveCar(int x, int y) {
	if (x + axisx > INT_MAX  || y + axisy > INT_MAX) {
		cout << "Number too big!" << endl;
		return;
	}

	int tempx = axisx;
	int tempy = axisy;

	axisx += x;
	axisy += y;

	cout << "You drove from " << tempx << ", " << tempy << " to " << axisx << ", " << axisy << "!" << endl;
}

void AutonomousCar::getCarName() {
	cout << "Car name: " << name << endl;
}

AutonomousCar::AutonomousCar() {
	name = "default";
	axisx = 0;
	axisy = 0;
}

AutonomousCar::AutonomousCar(string str) {
	name = str;
	axisx = 0;
	axisy = 0;
}