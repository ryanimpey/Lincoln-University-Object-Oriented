/*
	CMP2090M OOP Lecture 10
	2017-2018 Academic Year
	Paul Baxter, UoL

	Robot Classes: workshop
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Robots
{
public:
	virtual void sayHello(void)
	{
		cout << "Hello, I am a basic Robot" << endl;
	}
};

class SocialRobots : public Robots
{
public:
	void sayHello(void)
	{
		cout << "Hello, I am a Social robot" << endl;
	}
};

class IndustrialRobots : public Robots
{
public:
	void sayHello(void)
	{
		cout << "Hello, I am an Industrial robot" << endl;
	}
};



void Operate(vector<Robots*> &in)
{
	for (int a = 0; a < (int)in.size(); a++)
	{
		in[a]->sayHello();
	}
}



int mainRobots(int argc, char* argv[])
{
	
	Robots *robot;		//pointer to base class
	SocialRobots sR;
	robot = &sR;
	IndustrialRobots iR;
	Robots r;

	vector<Robots*> robotContainer;

	robotContainer.push_back(robot);
	robotContainer.push_back(&iR);
	robotContainer.push_back(&r);

	for (int a = 0; a < (int)robotContainer.size(); a++)
	{
		robotContainer[a]->sayHello();
	}

	cout << endl;

	Operate(robotContainer);

	cout << endl;
	system("pause");

	return 0;
}



