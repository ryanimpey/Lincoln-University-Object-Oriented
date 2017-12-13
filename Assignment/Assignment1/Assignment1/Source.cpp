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

	//Push welcome screen to console
	cout << " ************************************" << endl;
	cout << "    Image Stacker / Image Scaler    " << endl;
	cout << " ************************************" << endl;

	//Create imageVector to store images in.
	vector<Image> imageVec;
	vector<Image>::iterator ivi;
	
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
		
		Image img(3264, 2448);
		img.readPPM(filePathC);
		imageVec.push_back(img);
	}
	cout << "]" << endl;

	//float bigEggs = calculateSingleSigma(fvec, calculateMedian(fvec), calculateStandard(fvec));
	//cout << bigEggs << endl;

	//Image meanImage = calculateMean(imageVec);
	//meanImage.writePPM("meanImage.ppm");

	//Image medianImage = calculateMedian(imageVec);
	//medianImage.writePPM("medianImage.ppm");

	Image sigmaImage = calculateSigma(imageVec);
	sigmaImage.writePPM("sigmaImage.ppm");

	//ScaledImage *timesTwoImage = new ScaledImage(1500, 1500);
	//timesTwoImage->readPPM("Images/Zoom/zIMG_1.ppm");

	//timesTwoImage->scaleTwoTimes();

	//timesTwoImage->writePPM("zIMG_1x2.ppm");

	//Image meanImage = calculateMean(imageVec);
	//meanImage.writePPM("meanImage.ppm");

	//cout << "Started median file creation..." << endl;
	//high_resolution_clock::time_point epochStart = high_resolution_clock::now(); //Create timer for median start
	//	Image medianImage = calculateMedian(imageVec); // Median image equals calculateMedian result
	//high_resolution_clock::time_point epochEnd = high_resolution_clock::now(); //Create timer for median end
	//medianImage.writePPM("medianImage.ppm"); // Write image to file
	//Image sigmaImage(imageVec.at(0).h, imageVec.at(0).w);
	//cout << "done median and standard" << endl;

	//for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {
	//	vector<float> redValues;
	//	vector<float> greenValues;
	//	vector<float> blueValues;

	//	for (ivi = imageVec.begin(); ivi != imageVec.end(); ivi++) {
	//		Image tempImage = *ivi;
	//		redValues.push_back(tempImage.pixels[i].r);
	//		greenValues.push_back(tempImage.pixels[i].g);
	//		blueValues.push_back(tempImage.pixels[i].b);
	//		//If image is less than median - (1*sd) or greater than median + (1*sd)
	//		//do this for each image, if the image pixel value is not in boundaries then remove it
	//		//for 13 images, in their own rgb array, if the value in that array is less than the one made by median[i] +/- standardImage[i] then remove it, loop with function overloading
	//	}

	//	calculateSigma(redValues, medianImage.pixels[i].r, standardImage.pixels[i].r);
	//	calculateSigma(greenValues, medianImage.pixels[i].g, standardImage.pixels[i].g);
	//	calculateSigma(blueValues, medianImage.pixels[i].b, standardImage.pixels[i].b);

	//}


	/*auto epochStartToMS = epochStart.time_since_epoch();
	auto epochEndToMS = epochEnd.time_since_epoch();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(epochEndToMS - epochStartToMS).count();
	cout << "Median File created in: " << millis << "ms" << endl;*/

	//Prevents auto close.
	int endbreak;
	cin >> noskipws >> endbreak;
	return 0;
}