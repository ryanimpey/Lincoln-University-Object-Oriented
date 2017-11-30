/*
	CMP2090M OOP Lecture 9
	2017-2018 Academic Year
	Paul Baxter, UoL

	Robot Classes, Inheritance
*/

#include <iostream>
#include <string>

using namespace std;

//remember: poor practice to include all class declarations and definitions in main...
//	...should split out into header/source files (don't forget header guards...)

// NOTE:
// As mentioned in the lecture, some functionality has been removed for you to
// work on in the workshop...

class Robot
{
public:
	Robot() : robotName("Generic") {}
	Robot(string n) : robotName(n) {}
	void sayHello(void)
	{
		cout << "Hello, I am a basic Robot" << endl;
	}
	void moveForward(void)
	{
		cout << robotName + " robot moving forward...";
		cout << " ... finished" << endl;
	}
	void setName(string name)
	{
		robotName = name;
	}
	string getName(void)
	{
		return robotName;
	}

private:
	string robotName;	//can't access directly from derived classes...
};

class SocialRobot : public Robot
{
public:
	SocialRobot(string name) : Robot(name) {}
	/*
			NEED TO IMPLEMENT STUFF HERE...
	*/
private:

};

class IndustrialRobot : public Robot
{
public:
	IndustrialRobot(string name) : Robot(name) {}
	/*
			NEED TO IMPLEMENT STUFF HERE...
	*/
private:

};


int mainRobot(int argc, char* argv[])
{
	cout << "Individual classes and objects: " << endl;
	Robot *r = new Robot();			//deletes for each of the following is at the bottom...
	SocialRobot *sR = new SocialRobot("Sam");
	IndustrialRobot *iR = new IndustrialRobot("Indiana");

	r->sayHello();
	sR->sayHello();
	sR->beSocial();
	iR->sayHello();
	iR->beProductive();

	cout << endl;
	cout << "Basic effect of 'virtual': " << endl;

	Robot *baseR = new SocialRobot("test");
	baseR->sayHello();		//virtual changes the way this works...

	cout << endl;
	cout << "Just assigning child object to base object doesn't work: " << endl;

	Robot testR;
	SocialRobot testS("testS");

	testR.sayHello();
	testS.sayHello();

	cout << endl;
	cout << "But it does work with pointers: " << endl;

	SocialRobot robotS("robotS");
	Robot robotR;
	Robot *pointerR = &robotR;	//bit silly, but just making a point...

	pointerR->sayHello();
	robotS.sayHello();

	pointerR = &robotS;	//this now does the expected if 'virtual' is used

	pointerR->sayHello();

	cout << endl;

	delete r, sR, iR;
	delete baseR;

	cout << endl;
	system("pause");

	return 0;
}
