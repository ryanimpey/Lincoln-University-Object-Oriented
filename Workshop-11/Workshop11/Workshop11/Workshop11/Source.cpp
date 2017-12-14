#include <iostream>
#include <string>

using namespace std;

void main() {	try
	{	
		//Required to be in string() as compilier will try throwing a char[] array otherwise which will be unhandled.
		throw string("error");
	}
	catch (std::string e)
	{
		std::cout << "Exception caught: " << e << std::endl;
	}	int endProg = 0;	cout << "Press any key to continue..." << endl;	cin >> noskipws >> endProg;
}