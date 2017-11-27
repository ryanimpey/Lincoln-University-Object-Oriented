#pragma once
#include <string>

using namespace std;
class Animal {
private:
	string name;
	int age;
public:
	Animal();
	Animal(string, int);
	~Animal();
	void setValue(string, int);
	string getName();
	int getAge();
};

class Zebra : public Animal{
public:
	Zebra();
	Zebra(string, int);
	void getInfo();
};

class Dolphin : public Animal {
public:
	Dolphin();
	Dolphin(string, int);
	void getInfo();
};