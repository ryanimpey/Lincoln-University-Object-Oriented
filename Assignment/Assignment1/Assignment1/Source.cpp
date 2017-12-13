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

	// Create start timer for image algorithm
	high_resolution_clock::time_point epochStart;
	// Create end timer for image algorithm
	high_resolution_clock::time_point epochEnd;
	// Capture current time for passing to logs later
	time_t timeNow;

	// Create new image for Mean Image
	Image *meanImage = new Image(3264, 2448);
	// Start Timer
	epochStart = high_resolution_clock::now();
	// Calculate mean value of image
	meanImage->calculateMean(imageVec);
	// Write image to file
	meanImage->writePPM("meanImage.ppm");
	// Write image information to log
	meanImage->imageInformation("meanImage");
	// Stop Timer
	epochEnd = high_resolution_clock::now();
	// Calculate start and stop difference
	calculateEpoch(epochStart, epochEnd);
	// Delete allocated memory for Mean Image pointer
	delete meanImage;


	// Create new image for Median Image
	Image *medianImage = new Image(3264, 2448);
	// Start Timer
	epochStart = high_resolution_clock::now();
	// Calculate median value of image
	medianImage->calculateMedian(imageVec);
	// Write image to file
	medianImage->writePPM("medianImage.ppm");
	// Write image information to file
	medianImage->imageInformation("medianImage");
	// Stop Timer
	epochEnd = high_resolution_clock::now();
	// Calculate start and stop difference
	calculateEpoch(epochStart, epochEnd);
	//Delete allocated memory for Median Image pointer
	delete medianImage;


	// Create new image for Sigma Image
	Image *sigmaImage = new Image(3264, 2448);
	// Start Timer
	epochStart = high_resolution_clock::now();
	// Calculate median value of image
	sigmaImage->calculateSigma(imageVec);
	// Write image to file
	sigmaImage->writePPM("sigmaImage.ppm");
	// Write image information to log
	sigmaImage->imageInformation("sigmaImage");
	// Stop Timer
	epochEnd = high_resolution_clock::now();
	// Calculate start and stop difference
	calculateEpoch(epochStart, epochEnd);
	//Delete allocated memory for Sigma Image pointer
	delete sigmaImage;


	// Create new scaled image for x2 zoom
	ScaledImage *timesTwoImage = new ScaledImage(1500, 1500);
	// Start Timer
	epochStart = high_resolution_clock::now();
	// Read in the image file
	timesTwoImage->readPPM("Images/Zoom/zIMG_1.ppm");
	// Scale image
	timesTwoImage->scaleNearestNeighbour(2);
	// Write image to file
	timesTwoImage->writePPM("NearestNeighbourX2.ppm");
	// Write image information to log
	timesTwoImage->imageInformation("NearestNeighbourX2", 2);
	// Stop Timer
	epochEnd = high_resolution_clock::now();
	// Calculate start and stop difference
	calculateEpoch(epochStart, epochEnd);
	//Delete allocated memory for x2 Image pointer
	delete timesTwoImage;


	// Create new scaled image for x2 zoom
	ScaledImage *timesFourImage = new ScaledImage(3000, 3000);
	// Start Timer
	epochStart = high_resolution_clock::now();
	// Read in the image file
	timesFourImage->readPPM("Images/Zoom/zIMG_1.ppm");
	// Scale image
	timesFourImage->scaleNearestNeighbour(4);
	// Write image to file
	timesFourImage->writePPM("NearestNeighbourX4.ppm");
	// Write image information to log
	timesTwoImage->imageInformation("NearestNeighbourX4", 4);
	// Stop Timer
	epochEnd = high_resolution_clock::now();
	// Calculate start and stop difference
	calculateEpoch(epochStart, epochEnd);
	//Delete allocated memory for x2 Image pointer
	delete timesFourImage;
	

	//Prevents auto close.
	int endbreak;
	cout << "End of Program. Press any key to continue" << endl;
	cin >> noskipws >> endbreak;
	return 0;
}