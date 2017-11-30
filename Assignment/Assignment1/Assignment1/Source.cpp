#include "image.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//Moving these here prevents already defined in image.obj error.
const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);

int main() {

	cout << "************************************" << endl;
	cout << "Image Stacker / Image Scaler" << endl;
	cout << "************************************" << endl;

	//****************************************************
	//As an example, read one ppm file and write it out to testPPM.ppm
	//We need to specify the dimensions of the image
	//****************************************************
	Image *img1 = new Image(3264, 2448);

	vector<Image> imageVec;
	vector<Image>::iterator iv;
	
	// Read In all images into imageVec
	cout << "// Reading Images //" << endl;
	cout << "[";
	for (int i = 1; i < 14; ++i) {
		//Convert string for each file to a char* for readPPM
		ostringstream filePath;
		filePath << "Images/ImageStacker_set1/IMG_" << i << ".ppm";
		string fileName = filePath.str();
		//cout << fileName << endl;
		const char *filePathC = fileName.c_str();
		
		Image img(3264, 2448, 0);
		img.readPPM(filePathC);
		imageVec.push_back(img);
	}
	cout << "]" << endl;

	///**img1 = */img1->readPPM("Images/ImageStacker_set1/IMG_12.ppm");

	//cout << "imageVec size:" << imageVec.size() << endl;

	//Write out all images
	/*int testInt = 1;
	for (iv = imageVec.begin(); iv != imageVec.end(); ++iv) {
		Image i = *iv;
		ostringstream fileP;
		fileP << testInt << ".ppm";
		string filePa = fileP.str();
		const char *filePathca = filePa.c_str();
		
		cout << filePa << endl;

		i.writePPM(filePathca);

		testInt++;
	}*/

	//	int num = imageVec.at(0).h;
	//	cout << num << endl;

	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {
		for (iv = imageVec.begin(); iv != imageVec.end(); ++iv) {
			Image tempImg = *iv;
			img1->pixels[i].r += tempImg.pixels[i].r;
			img1->pixels[i].g += tempImg.pixels[i].g;
			img1->pixels[i].b += tempImg.pixels[i].b;

		}
		img1->pixels[i].r /= imageVec.size();
		img1->pixels[i].g /= imageVec.size();
		img1->pixels[i].b /= imageVec.size();
	}

	//You can access the individual pixel data
	//This accesses and writes out the r, g, b pixel values for the first pixel
	//Values are multiplied by 255 as they are 'clamped' between 0 and 1
	//cout << (img1->pixels[0].r) * 255 << endl;
	//cout << (img1->pixels[1].g) * 255 << endl;
	//cout << (img1->pixels[0].b) * 255 << endl;

	//***************************************************
	//Output the image data to a file for viewing
	//***************************************************

	img1->writePPM("testPPM.ppm");

	delete img1;

	//Prevents auto close
	int endbreak;
	cin >> noskipws >> endbreak;
	return 0;
}