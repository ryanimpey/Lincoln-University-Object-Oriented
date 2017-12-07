#include <iostream>

using namespace std;

class A {
public:
	virtual~A() {};
};

class B : public A {
public:
	~B() {};
};

class C : public B {
public:
	~C() {
		cout << "C destructor" << endl;
	}
};


void main() {

	A *a = new C;

	delete a;

	int eof = 0;
	cin >> eof;
}