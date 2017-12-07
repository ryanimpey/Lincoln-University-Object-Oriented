#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
	virtual void info() = 0; //Pure virtual
	virtual void speak() = 0;
	virtual ~Person() {
		cout << "Person Destroyed" << endl;
	};
/*
	Implement pure virtual functions for:
		info()
		speak()
	and a virtual destructor (printing a message)
*/
};

class UoLPerson : public Person
{
private:
	int id;
public:
	UoLPerson() {
		id = 0;
		cout << "UoLPerson constructor called." << endl;
	}
	UoLPerson(int ID) {
		id = ID;
		cout << "UoLPerson parameterised constructor called." << endl;
	}
	virtual ~UoLPerson()
	{
		cout << "...UoLPerson destructor called" << endl;
	}
	void info() { cout << "UoL ID: " << id << endl; }
	virtual void speak() { cout << "Hi, I am from the University of Lincoln." << endl; }
};

class Staff : public UoLPerson
{
	Staff() {
		cout << "Staff constructor called" << end;
	}
	Staff(int id) : UoLPerson(id) {
		cout << "Staff parameterised constructor called." << endl;
	}
	~Staff() {
		cout << "Staff destructor called" << endl;
	}
	virtual void speak() {
		cout << "Hi, I am a staff member from the University of Lincoln" << endl;
	}
	void studyInfo() {
		cout << "I work there" << endl;
	}
/*
	Implement content of this class following Lecture
	Also add overloaded constructor taking intID as argument
		(similar to UoLPerson(int ID) )
*/
};

class Student : public UoLPerson
{
public:
	Student() { cout << "Student constructor called." << endl; }
	Student(int id) : UoLPerson(id) { cout << "Student parameterised constructor called." << endl; }
	~Student() { cout << "... Student destructor called" << endl; }
	virtual void speak() { cout << "Hi, I am a student from University of Lincoln" << endl; }
	void studyInfo() { cout << "I study there." << endl; }
};

class StudentCS : public Student
{
public:
	StudentCS() : Student(111) { cout << "StudentCS constructor called." << endl; }
	~StudentCS() { cout << "... CS student destructor called" << endl; }
	virtual void speak() { cout << "Hi, I am a computer science student from University of Lincoln" << endl; }
	void skillInfo() { cout << "I can code in C++. " << endl; }
};

void Info(vector<Person*> &in)
{
	Person temp = &in;
	temp.info();
/*
	Implement content of this function to call info() of
	all contents of the vector passed in
*/
}

int mainPerson() {

	//creation of example objects
	UoLPerson person(1);
	cout << endl;
	Student student(2);
	cout << endl;
	StudentCS cs;
	cout << endl;
	Staff staff(4);
	cout << endl;

	//allocating memory - release below
	Person *a = new StudentCS();
	a->speak();

	cout << endl;

	//creating a vector of person pointers
	vector<Person*> people;

	people.push_back(&person);
	people.push_back(&student);
	people.push_back(&cs);
	people.push_back(&staff);

	cout << endl;

	//call to the function to print out info of each object
	Info(people);

	cout << endl;

	delete a;

	cout << endl;
	system("pause");
	return 0;
}
