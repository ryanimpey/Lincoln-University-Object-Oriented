#ifndef SAMPLECLASS_H
#define SAMPLECLASS_H

/*
	CMP2090M OOP Lecture 9
	2017-2018 Academic Year
	Paul Baxter, UoL

	Sample classes, simple inheritance relationship, with virtual functions
*/

#include <iostream>

class SampleClass
{
public:
	virtual ~SampleClass();
	virtual void printOut(void);
private:
	int num;
};


class SampleDerived : public SampleClass
{
public:
	~SampleDerived();
	void printOut(void);
};

#endif
