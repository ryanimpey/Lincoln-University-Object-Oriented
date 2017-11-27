// Workshop6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "robot.h"
#include "shape.h"
#include "animal.h"
#include "statistics.h"
#include <iostream>
#include <string>
#include <vector>


int main()
{
	//Part One
	/*AutonomousCar *myCar = new AutonomousCar("egg");

	myCar->getCarName();
	myCar->setCarName("doug!");
	myCar->getCarName();
	myCar->turn();
	myCar->driveCar(63, 298);

	delete myCar;*/

	//Part Two
	/*Rectangle myRect(25, 10);

	myRect.calculateArea();

	Triangle myTri(8, 5);

	myTri.calculateArea();

    return 0;*/

	//Part Three
	/*Zebra myZeb("doug", 23);
	myZeb.getInfo();

	Dolphin myDol("alan", 42);
	myDol.getInfo();*/

	//Part Four
	vector<float> myVector = {2,4,6,8 };
	average(myVector);

	vector<float> unsortVector = { 5,4,2,3,1, 6 };
	median(unsortVector);

	standardDev(myVector);
}
