#pragma once
#include <iostream>

using namespace std;

class Matrix{
public:
	Matrix();
	~Matrix();
	void fillMatrix(float f);
	void getMatrix();
private:
	float matrix[5][5];
};