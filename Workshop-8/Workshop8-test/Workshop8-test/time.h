#pragma once

class Time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time();
	Time(int, int, int);
	~Time();
	void printTime();
	Time operator+(const Time);
	Time operator<(const Time);
};