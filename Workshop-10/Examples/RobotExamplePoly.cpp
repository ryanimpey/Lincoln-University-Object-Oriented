/*
	CMP2090M OOP Lecture 10
	2017-2018 Academic Year
	Paul Baxter, UoL

	Robot Classes: Polymorphism
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;



class Robot
{
public:
	virtual void sayHello(void)
	{
		cout << "Hello, I am a basic Robot" << endl;
	}
};

class SocialRobot : public Robot
{
public:
	void sayHello(void)
	{
		cout << "Hello, I am a Social robot" << endl;
	}
};

class IndustrialRobot : public Robot
{
public:
	void sayHello(void)
	{
		cout << "Hello, I am an Industrial robot" << endl;
	}
};

class BrokenRobot : public Robot
{
public:
	void sayHello(void)
	{
		cout << "heLoL, I robot BrOKen am" << endl;
	}
};

void Greet(Robot &in)
{
	in.sayHello();
}



int mainRobot(int argc, char* argv[])
{
	srand(time(0));		//seed pseudo-random number generator
	
	Robot *robot;		//pointer to base class

	//cout << rand()%3 << endl;	//remainder...

	switch (rand() % 3)	
	{
	case 0:
		robot = new SocialRobot;
		break;
	case 1:
		robot = new IndustrialRobot;
		break;
	case 2:
		robot = new BrokenRobot;
		break;
	default:
		robot = new Robot;
	}

	Greet(*robot);		//can only be resolved at run-time!
						// alternative would be to implement separate functions for each type...

	delete robot;		//remember to release memory!

	cout << endl;
	system("pause");

	return 0;
}



