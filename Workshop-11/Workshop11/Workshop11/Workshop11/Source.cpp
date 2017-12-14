#include <iostream>
#include <string>

using namespace std;

void f1(int k) {
	string err = "F1 ERROR";
	if (!k) {
		throw err;
		cout << "f1: error!" << endl;
	}
	else {
		cout << "f1 success" << endl;
	}
}

void f2(int j) {
	try {
		f1(j);
	}
	catch (string e) {
		cout << "exception caught in f2" << endl;
		throw e;
	}
	cout << "f2 success" << endl;
}void f3(int i) {
	f2(i);
	cout << "f3 success" << endl;
}

//https://msdn.microsoft.com/en-us/library/9yb4317s.aspx

void main() {	try {
		f3(0); //compare this to situation where argument is 0
	}
	catch (string e) {
		cout << "Caught exception: " << e << endl;
	}	int endProg = 0;	cout << "Press any key to continue..." << endl;	cin >> noskipws >> endProg;
	//// Part One	//try
	//{	
	//	//Required to be in string() as compilier will try throwing a char[] array otherwise which will be unhandled.
	//	throw string("error");
	//}
	//catch (std::string e)
	//{
	//	std::cout << "Exception caught: " << e << std::endl;
	//}

}