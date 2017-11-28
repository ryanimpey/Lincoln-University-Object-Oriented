#include "matrix.h"

#include <iostream>
#include <vector>

using namespace std;

Matrix::Matrix() {
	int dimension = 3;
	height = 3;
	width = 3;
	mat.resize(dimension);
	for(int i = 0; i < dimension; ++i){
		mat[i].resize(dimension);
	}
}

Matrix::Matrix(int h, int w, int value = 0) {
	mat.resize(h);
	int toReplace = value;

	height = h;
	width = w;

	for (int i = 0; i < h; ++i) {
		mat[i].resize(w);
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			mat[i][j] = toReplace;
		}
	}
}

Matrix::~Matrix() {
	cout << "Matrix destroyed" << endl;
}

int Matrix::getHeight() {
	return height;
}

int Matrix::getWidth() {
	return width;
}

ostream& operator<<(ostream& os, const Matrix &m) {

	int height = m.height;
	int width = m.width;


	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			os << m.mat[i][j] << " ";
		}
		os << endl;
	}

	return os;

}