
#pragma once

#include <iostream>

using namespace std;
class Robot
{
private:
	string name;
	float length;
	float position;
	int angle;

public:
	Robot();
	Robot(string n, float l);
	~Robot();

	bool forward(float m);
	bool turn(int a);
	float getPosition();
	void info();

};

class AutonomousCar:Robot {
public:
	AutonomousCar();
	AutonomousCar(string);
	void setCarName(string);
	void getCarName();
	bool turn();
	void driveCar(int, int);
private:
	string name;
	int axisx;
	int axisy;
};
