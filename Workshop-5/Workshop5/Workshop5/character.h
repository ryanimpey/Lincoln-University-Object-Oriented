#pragma once
#include <string>

using namespace std;

class Character {
public:
	Character();
	Character(string n, bool tot, string tri, string tre);
	~Character();
	void getName();
	string setName(string str);
	void getTrickOrTreat();
	bool setTrickOrTreat(bool t);
	void getTrick();
	bool setTrick(string str);
	void getTreat();
	bool setTreat(string str);

private:
	string name;
	bool trickOrTreat;
	string trick;
	string treat;
};