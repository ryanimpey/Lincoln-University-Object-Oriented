#include "stdafx.h"
#include "matrix.h"

#include <iostream>
#include <vector>

using namespace std;

Matrix::Matrix() {
	int dimension = 3;
	mat.resize(dimension);
	for(int i = 0; i < dimension; ++i){
		mat[i].resize(dimension);
	}
}

Matrix::Matrix(int height, int width, int value = 0) {
	mat.resize(height);
	for (int i = 0; i < height; ++i) {
		mat[i].resize(width);
	}
}

Matrix::~Matrix() {
	cout << "Matrix destroyed" << endl;
}

Matrix Matrix::operator+(const Matrix a) {
	Matrix result;



	return result;
}