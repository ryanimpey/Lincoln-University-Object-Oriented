#pragma once

#include <vector>

using namespace std;

class Matrix {
private:
	vector<vector<int>> mat;
public:
	Matrix();
	Matrix(int, int, int);
	~Matrix();
	Matrix operator+(const Matrix);
	Matrix operator-(const Matrix);
	Matrix operator*(const Matrix);
	Matrix operator<<(const Matrix);
};