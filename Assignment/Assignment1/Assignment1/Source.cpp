#include "image.h"
#include "calculations.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Moving these here prevents already defined in image.obj error.
const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);

int main() {

	cout << 5 + NULL + 5 << endl;

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

	//Image meanImage = calculateMean(imageVec);
	//meanImage.writePPM("meanImage.ppm");



	//cout << "Started median file creation..." << endl;
	//high_resolution_clock::time_point epochStart = high_resolution_clock::now(); //Create timer for median start
	//	Image medianImage = calculateMedian(imageVec); // Median image equals calculateMedian result
	//high_resolution_clock::time_point epochEnd = high_resolution_clock::now(); //Create timer for median end
	//medianImage.writePPM("medianImage.ppm"); // Write image to file

	Image standardImage = calculateStandard(imageVec);

	/*auto epochStartToMS = epochStart.time_since_epoch();
	auto epochEndToMS = epochEnd.time_since_epoch();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(epochEndToMS - epochStartToMS).count();
	cout << "Median File created in: " << millis << "ms" << endl;*/

	//Prevents auto close.
	int endbreak;
	cin >> noskipws >> endbreak;
	return 0;
}