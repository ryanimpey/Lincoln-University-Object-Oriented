#pragma once

#include <string>
#include <iostream>

using namespace std;

class Robot {
public:
	Robot();
	Robot(string n);
	void sayHello(void);
	void moveForward(void);
	void setName(string name);
	string getName(void);
private:
	string robotName;	//can't access directly from derived classes...
};