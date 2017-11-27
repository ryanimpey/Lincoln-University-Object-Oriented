#include "stdafx.h"
#include <string>
#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal() {
	name = "Default";
	age = 0;
}

Animal::Animal(string str, int i) {
	name = str;
	age = i;
	cout << "Animal Created" << endl;
}

Animal::~Animal() {
	cout << "Animal destroyed" << endl;
}

void Animal::setValue(string str, int i) {
	name = str;
	age = i;
}

string Animal::getName(){
	return name;
}

int Animal::getAge() {
	return age;
}

Zebra::Zebra() :Animal() {

}

Zebra::Zebra(string str, int i): Animal(str, i) {
}

void Zebra::getInfo() {
	cout << "Hello I am a zebra, my name is " << getName() << " and my age is " << getAge() << "." << endl;
}

Dolphin::Dolphin() :Animal() {

}

Dolphin::Dolphin(string str, int i) : Animal(str, i) {
	
}

void Dolphin::getInfo() {
	cout << "Hello I am a dolphin, my name is " << getName() << " and my age is " << getAge() << "." << endl;
}