#include "stdafx.h"
#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

Matrix::Matrix() {
	matrix[5][5];
}

void Matrix::fillMatrix(float f) {
	
}

void Matrix::getMatrix() {
	float *ma;
	ma = *matrix;
	cout << ma << endl;
};

