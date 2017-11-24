// Workshop5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Robot.h"
#include "character.h"
#include "matrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;
int main() {
	//Part One

	//Robot *a = new Robot("a", 1);
	//Robot *b = new Robot("b", 2);
	//Robot *c = new Robot("c", 3);

	//vector<Robot> robots;

	//cout << "what happened here" << endl;

	//robots.push_back(*a);
	//robots.push_back(*b);
	//robots.push_back(*c);

	//cout << "what happended? " << endl;
	//for (int i = 0; i < robots.size(); i++)
	//{
	//	robots[i].forward((float)i + 1);
	//	robots[i].turn(90 + i);
	//	robots[i].info();
	//}

	//delete a;
	//delete b;
	//delete c;

	//cin.get();

	//Part Two
	/*Character *spiderman = new Character("Spiderman", true, "silly string", "big egg!");
	Character *witch = new Character("Witch", true, "poison", "potion");
	Character *spookymonk = new Character("Spooky Monk!", false, "angry bloke", "not angry bloke");

	cout << "Please Select either 1. Spiderman, 2. Witch, or 3. Spooky Monk" << endl;
	int input = 0;

	cin >> input;

	if (input == 1) {
		spiderman->getTrickOrTreat();
	}
	else if (input == 2) {
		witch->getTrickOrTreat();
	}
	else if (input == 3) {
		spookymonk->getTrickOrTreat();
	}
	else {
		cout << "No Character Selected" << endl;
	};*/

	//Part Three


	Matrix newMatrix;

	newMatrix.getMatrix();

	newMatrix.fillMatrix(1.2);

	newMatrix.setMatrix(1.4, 1,1);

	newMatrix.getMatrix();

	//Bad mem leak here

	return 0;
}
