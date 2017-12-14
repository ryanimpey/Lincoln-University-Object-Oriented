/*
	CMP2090M OOP Lecture 11
	2017-2018 Academic Year
	Paul Baxter, UoL

	File Example: flags and exceptions
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> Split(string, char);
float StoF(string);
vector<float> Convert(vector<string>);
float Median(vector<float>);

int main()
{
	ifstream inFile;
	inFile.open("data.dat");
	string inLine;

	if (inFile.is_open())
	{
		//checking flag...
		getline(inFile, inLine);
		cout << inLine << endl;
	}
	else
	{
		cout << "Error opening file..." << endl;
	}

	//split the string into substrings
	vector<string> strNums = Split(inLine, ',');

	//turn into floats
	vector<float> nums = Convert(strNums);
	cout << "Converted vector of strings into floats..." << endl;

	vector<float> oops;		//if there is an empty vector...

	try
	{
		cout << "Median: " << Median(nums) << endl;
	}
	catch (domain_error e)
	{
		cout << e.what() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}


/*
	A lot of inefficiencies in the following code...
*/

vector<string> Split(string in, char delim)
{
	//from lecture 4!!!
	vector<string> toReturn;
	stringstream ss;
	ss.str(in);
	string sub;
	while (getline(ss, sub, delim))
	{
		toReturn.push_back(sub);
	}
	return toReturn;
}

float StoF(string in)
{
	float toReturn;
	stringstream ss;
	ss.str(in);
	ss >> toReturn;
	return toReturn;
}

vector<float> Convert(vector<string> in)
{
	vector<float> out;
	for (int a = 0; a < (int)in.size(); a++)
	{
		out.push_back(StoF(in[a]));
	}
	return out;
}

float Median(vector<float> in)
{
	float median = 0.0;
	int size = (int)in.size();

	if (size == 0)
	{
		throw domain_error("median of an empty vector!");
	}

	sort(in.begin(), in.end());

	int middle = size / 2;

	if ((size % 2) == 0)
	{
		median = (in[middle] + in[middle - 1]) / 2;
	}
	else
	{
		median = in[middle];
	}

	return median;
}
