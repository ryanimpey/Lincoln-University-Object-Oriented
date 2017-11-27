#include "stdafx.h"
#include "message.h"
#include <string>
#include <iostream>

using namespace std;

Message::Message() {
	myMessage = "Default Message.";
}

Message::Message(string str) {
	myMessage = str;
}

Message::~Message() {
	cout << "Message class: "<< myMessage << " deleted." << endl;
}

void Message::print() {
	cout << myMessage << endl;
}

void Message::print(string str) {
	cout << myMessage << " " << str << endl;
}