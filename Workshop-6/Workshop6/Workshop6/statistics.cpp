#include "stdafx.h"
#include "statistics.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

float average(vector<float> aVec) {
	vector<float>::iterator ai;
	float temp = 0;
	int size = aVec.size();

	for (ai = aVec.begin(); ai != aVec.end(); ++ai) {
		temp += *ai;
	}

	temp /= size;

	cout << "Average of these values: " << temp << endl;
	return temp;
};

float median(vector<float> mVec) {
	vector<float>::iterator mi;
	sort(mVec.begin(), mVec.end());


	if (mVec.size() % 2 == 0) {
		cout << "Median Value is: ";
		cout << mVec.at((mVec.size() / 2)-1) << " and " << mVec.at(mVec.size() / 2) << endl;
	}
	else {
		cout << "Median Value: ";
		cout << mVec.at(mVec.size() / 2) << endl;
	}

	return 1;
};

float standardDev(vector<float> sVec) {
	float mean = average(sVec);
	float variance = 0;
	vector<float>::iterator si;

	for (si = sVec.begin(); si != sVec.end(); ++si) {
		float temp = *si - mean;
		*si = temp * temp;
		variance += *si;
	}

	variance /= sVec.size();

	float result = sqrt(variance);

	result = ceilf(result * 100) / 100;

	cout << "Standard Deviation: " << result << endl;

	return 1;
};