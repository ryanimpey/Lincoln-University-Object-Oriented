#pragma once

#include <string>
#include <iostream>

using namespace std;

class Robot {
public:
	Robot();
	Robot(string n);
	virtual void sayHello() = 0;
	void moveForward(void);
	void setName(string name);
	string getName(void);
private:
	string robotName;	//can't access directly from derived classes...
};

class SocialRobot : public Robot {
public:
	SocialRobot(string);
	virtual void sayHello();
};

class IndustrialRobot : public Robot {
public:
	IndustrialRobot(string);
	virtual void sayHello();
};