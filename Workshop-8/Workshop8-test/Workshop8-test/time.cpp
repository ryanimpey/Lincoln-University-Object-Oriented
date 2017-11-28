#include "stdafx.h"
#include "time.h"
#include <iostream>
#include <string>

using namespace std;

Time::Time() {
	hours = 0;
	minutes = 0;
	seconds = 0;

}

Time::Time(int h, int m, int s) {
	hours = h;
	minutes = m;
	seconds = s;
}

Time::~Time() {
	cout << "Time is destroyed." << endl;
}

void Time::printTime() {
	cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
}

Time Time::operator+(const Time t) {
	Time result;

	if (hours + t.hours > 24 || minutes + t.minutes > 60 || seconds + t.seconds > 60) {
		cout << "Time over allowed length" << endl;
	}
	else {
		result.hours = hours + t.hours;
		result.minutes = minutes + t.minutes;
		result.seconds = seconds + t.seconds;
	}

	return result;
}