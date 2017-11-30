#include "image.h"
#include "algorithms.h"
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

	//Push welcome screen to console
	cout << " ************************************" << endl;
	cout << "    Image Stacker / Image Scaler    " << endl;
	cout << " ************************************" << endl;

	//Create imageVector to store images in.
	vector<Image> imageVec;
	
	// Read all images and push_back into imageVec. Creates nice [****] loading indicator
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


	//You can access the individual pixel data
	//Values are multiplied by 255 as they are 'clamped' between 0 and 1
	//cout << (img1->pixels[0].r) * 255 << endl;
	//cout << (img1->pixels[1].g) * 255 << endl;
	//cout << (img1->pixels[0].b) * 255 << endl;


	//Create new algorithms object from Algorithms class
	Algorithms *algorithmObj = new Algorithms;
	//Calls the meanBlend method passing through the previously created.
	algorithmObj->meanBlend(imageVec);
	algorithmObj->medianBlend(imageVec);

	//Prevents auto close.
	int endbreak;
	cin >> noskipws >> endbreak;
	return 0;
}