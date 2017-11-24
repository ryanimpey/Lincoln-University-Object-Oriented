#include "stdafx.h"
#include "character.h"
#include <iostream>
#include <string>

using namespace std;

Character::Character() {
	name = "default";
	trickOrTreat = false;
	trick = "egg attack";
	treat = "spaghetti";

	cout << "Default character created." << endl;
}

Character::Character(string n, bool tot, string tri, string tre) {
	name = n;
	trickOrTreat = tot;
	trick = tri;
	treat = tre;

	cout << "New Character Created!:" << endl;
	cout << "  Name:" << name << endl;
	cout << "  TrickOrTreat:" << trickOrTreat << endl;
	cout << "  Trick:" << trick << endl;
	cout << "  Treat:" << treat << endl;
}

Character::~Character() {
	cout << "Character Destroyed." << endl;
}

void Character::getName() {
	cout << "Name: " << name << endl;
}

string Character::setName(string str) {
	name = str;
	return name;
}

void Character::getTrickOrTreat() {
	if (trickOrTreat) {
		cout << "Treat!: " << treat << endl;
	}
	else {
		cout << "Trick!" << trick << endl;
	}
}

bool Character::setTrickOrTreat(bool t) {
	trickOrTreat = t;
	return true;
}

void Character::getTrick() {
	cout << "Trick: " << trick << endl;
}

bool Character::setTrick(string str) {
	trick = str;
	return true;
}

void Character::getTreat() {
	cout << "Treat: " << treat << endl;
}

bool Character::setTreat(string str) {
	treat = str;
	return true;
}
