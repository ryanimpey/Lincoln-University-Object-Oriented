#pragma once
#include <vector>
#include <ostream>

using namespace std;

class Matrix {
private:
	vector<vector<int>> mat;
	int height;
	int width;
public:
	Matrix();
	Matrix(int, int, int);
	~Matrix();
	int getHeight();
	int getWidth();
	Matrix operator+(const Matrix);
	Matrix operator-(const Matrix);
	Matrix operator*(const Matrix);
	friend ostream& operator<<(ostream& os, const Matrix &obj);
};