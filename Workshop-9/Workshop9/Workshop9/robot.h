#pragma once

#include <string>
#include <iostream>

using namespace std;

class Robot {
public:
	Robot();
	Robot(string n);
	virtual void sayHello() = 0;
	virtual void moveForward() = 0;
	virtual void setName(string) = 0;
	virtual string getName() = 0;
};

class SocialRobot : public Robot {
public:
	SocialRobot(string);
	virtual void sayHello();
	virtual void moveForward();
	virtual void setName(string);
	virtual string getName();
private:
	string robotName;
};

class IndustrialRobot : public Robot {
public:
	IndustrialRobot(string);
	virtual void sayHello();
private:
	string robotName;
};