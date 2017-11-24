#pragma once
#include <iostream>
#include <array>

using namespace std;

class Matrix{
public:
	Matrix();
	~Matrix();
	void fillMatrix(float f);
	void getMatrix();
	bool setMatrix(float f, int row, int col);
private:
	array<array<float, 3>, 3> myMatrix;
};