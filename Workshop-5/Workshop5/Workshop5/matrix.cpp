#include "stdafx.h"
#include <iostream>
#include <string>
#include "matrix.h"
#include <array>

using namespace std;

Matrix::Matrix() {
	myMatrix = { {} };
}

void Matrix::fillMatrix(float f) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			myMatrix[i][j] = f;
		}
	}
}

void Matrix::getMatrix() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << " " << myMatrix[i][j];
		}
		std::cout << std::endl;
	}
};

bool Matrix::setMatrix(float f, int row, int col) {

	if (row >= 3 || col >= 3) {
		cout << "Value larger than matrix" << endl;
		return false;
	}
	else {
		myMatrix[row][col] = f;
	}

}