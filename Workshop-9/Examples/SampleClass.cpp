#include "SampleClass.h"

/*
	CMP2090M OOP Lecture 9
	2017-2018 Academic Year
	Paul Baxter, UoL

	method definitions for SampleClass and SampleDerived
*/

SampleClass::~SampleClass()
{
	std::cout << "SampleClass destructor..." << std::endl;
}

void SampleClass::printOut(void)
{
	std::cout << "Hello, I am an instance of SampleClass!" << std::endl;
}

////

SampleDerived::~SampleDerived()
{
	std::cout << "SampleDerived destructor!" << std::endl;
}

void SampleDerived::printOut(void)
{
	std::cout << "I am a SampleDerived instance" << std::endl;
}
