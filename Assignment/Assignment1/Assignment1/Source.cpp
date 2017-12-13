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

	
	vector<Image> imageVec; // Create imageVector to store images in.
	
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

	high_resolution_clock::time_point epochStart; // Create start timer for image algorithm
	high_resolution_clock::time_point epochEnd; // Create end timer for image algorithm

	Image *meanImage = new Image(3264, 2448); // Create new image for Mean Image
	epochStart = high_resolution_clock::now(); // Start Timer
	meanImage->calculateMean(imageVec); // Calculate mean value of image
	meanImage->writePPM("meanImage.ppm"); // Write image to file
	epochEnd = high_resolution_clock::now(); // Stop Timer
	calculateEpoch(epochStart, epochEnd); // Calculate start and stop difference
	delete meanImage; // Delete allocated memory for Mean Image pointer

	Image *medianImage = new Image(3264, 2448); // Create new image for Median Image
	epochStart = high_resolution_clock::now(); // Start Timer
	medianImage->calculateMedian(imageVec); // Calculate median value of image
	medianImage->writePPM("medianImage.ppm"); // Write image to file
	epochEnd = high_resolution_clock::now(); // Stop Timer
	calculateEpoch(epochStart, epochEnd); // Calculate start and stop difference
	delete medianImage; //Delete allocated memory for Median Image pointer

	Image *sigmaImage = new Image(3264, 2448); // Create new image for Sigma Image
	epochStart = high_resolution_clock::now(); // Start Timer
	sigmaImage->calculateSigma(imageVec); // Calculate median value of image
	sigmaImage->writePPM("sigmaImage.ppm"); // Write image to file
	epochEnd = high_resolution_clock::now(); // Stop Timer
	calculateEpoch(epochStart, epochEnd); // Calculate start and stop difference
	delete sigmaImage; //Delete allocated memory for Sigma Image pointer

	ScaledImage *timesTwoImage = new ScaledImage(1500, 1500); // Create new scaled image for x2 zoom
	epochStart = high_resolution_clock::now(); // Start Timer
	timesTwoImage->readPPM("Images/Zoom/zIMG_1.ppm"); // Read in the image file
	timesTwoImage->scaleNearestNeighbour(2); // Scale image
	timesTwoImage->writePPM("NearestNeighbourX2.ppm"); // Write image to file
	epochEnd = high_resolution_clock::now(); // Stop Timer
	calculateEpoch(epochStart, epochEnd); // Calculate start and stop difference
	delete timesTwoImage;  //Delete allocated memory for x2 Image pointer

	ScaledImage *timesFourImage = new ScaledImage(3000, 3000); // Create new scaled image for x2 zoom
	epochStart = high_resolution_clock::now(); // Start Timer
	timesFourImage->readPPM("Images/Zoom/zIMG_1.ppm"); // Read in the image file
	timesFourImage->scaleNearestNeighbour(4); // Scale image
	timesFourImage->writePPM("NearestNeighbourX4.ppm"); // Write image to file
	epochEnd = high_resolution_clock::now(); // Stop Timer
	calculateEpoch(epochStart, epochEnd); // Calculate start and stop difference
	delete timesFourImage;  //Delete allocated memory for x2 Image pointer
	

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

	//cout << "Started median file creation..." << endl;
	//high_resolution_clock::time_point epochStart = high_resolution_clock::now(); //Create timer for median start
	//	Image medianImage = calculateMedian(imageVec); // Median image equals calculateMedian result
	//high_resolution_clock::time_point epochEnd = high_resolution_clock::now(); //Create timer for median end
	//medianImage.writePPM("medianImage.ppm"); // Write image to file
	//Image sigmaImage(imageVec.at(0).h, imageVec.at(0).w);
	//cout << "done median and standard" << endl;
	/*auto epochStartToMS = epochStart.time_since_epoch();
	auto epochEndToMS = epochEnd.time_since_epoch();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(epochEndToMS - epochStartToMS).count();
	cout << "Median File created in: " << millis << "ms" << endl;*/

	//Prevents auto close.
	int endbreak;
	cin >> noskipws >> endbreak;
	return 0;
}