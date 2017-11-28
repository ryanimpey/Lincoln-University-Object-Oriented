#include <iostream>
#include "image.h"

using namespace std;

int main() {
	cout << "************************************" << endl;
	cout << "Image Stacker / Image Scaler" << endl;
	cout << "************************************" << endl;

	//****************************************************
	//As an example, read one ppm file and write it out to testPPM.ppm
	//We need to specify the dimensions of the image
	//****************************************************
	Image *img1 = new Image(3264, 2448);

	*img1 = img1->readPPM("Images/ImageStacker_set1/IMG_1.ppm");

	//You can access the individual pixel data
	//This accesses and writes out the r, g, b pixel values for the first pixel
	//Values are multiplied by 255 as they are 'clamped' between 0 and 1
	cout << (img1->pixels[0].r) * 255 << endl;
	cout << (img1->pixels[1].g) * 255 << endl;
	cout << (img1->pixels[0].b) * 255 << endl;

	//***************************************************
	//Output the image data to a file for viewing
	//***************************************************
	img1->writePPM("testPPM.ppm");

	delete img1;

	int endbreak;
	cin >> noskipws >> endbreak;
	return 0;
}