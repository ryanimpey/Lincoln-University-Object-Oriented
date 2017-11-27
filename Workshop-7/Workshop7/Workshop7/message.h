#pragma once
#include <string>

using namespace std;

class Message {
public:
	Message();
	Message(string);
	~Message();
	void print();
	void print(string);
private:
	string myMessage;
};