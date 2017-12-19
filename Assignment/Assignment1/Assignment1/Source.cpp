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

	
	//vector<Image*> imageVec; // Create imageVector to store images in.
	//
	//// Read all images and push_back into imageVec. Creates nice [****] loading indicator
	//cout << "// Reading Images //" << endl;
	//cout << "[";
	//for (int i = 1; i < 11; ++i) {
	//	//Convert string for each file to a char* for readPPM
	//	ostringstream filePath;
	//	filePath << "Images/ImageStacker_set2/IMG_" << i << ".ppm";
	//	string fileName = filePath.str();
	//	//cout << fileName << endl;
	//	const char *filePathC = fileName.c_str();
	//	cout << "*";
	//	Image *img = new Image(4592, 3056);
	//	img->readPPM(filePathC);
	//	imageVec.push_back(img);
	//}
	//cout << "]" << endl;

	////Create start timer for image algorithm
	//high_resolution_clock::time_point epochStart;
	//// Create end timer for image algorithm
	//high_resolution_clock::time_point epochEnd;
	//// Capture current time for passing to logs later
	//time_t timeNow;

	//// Create new image for Mean Image
	//Image *meanImage = new Image(4592, 3056);
	//// Start Timer
	//epochStart = high_resolution_clock::now();
	//// Calculate mean value of image
	//meanImage->calculateMean(imageVec);
	//// Write image to file
	//meanImage->writePPM("meanImage.ppm");
	//// Write image information to log
	//getInfo(*meanImage, "meanImage");
	//// Stop Timer
	//epochEnd = high_resolution_clock::now();
	//// Calculate start and stop difference
	//calculateEpoch(epochStart, epochEnd);
	//// Delete allocated memory for Mean Image pointer
	//delete meanImage;


	//// Create new image for Median Image
	//Image *medianImage = new Image(4592, 3056);
	//// Start Timer
	//epochStart = high_resolution_clock::now();
	//// Calculate median value of image
	//medianImage->calculateMedian(imageVec);
	//// Write image to file
	//medianImage->writePPM("medianImage.ppm");
	//// Write image information to log
	//getInfo(*medianImage, "medianImage");
	//// Stop Timer
	//epochEnd = high_resolution_clock::now();
	//// Calculate start and stop difference
	//calculateEpoch(epochStart, epochEnd);
	////Delete allocated memory for Median Image pointer
	//delete medianImage;


	//// Create new image for Sigma Image
	//Image *sigmaImage = new Image(4592, 3056);
	//// Start Timer
	//epochStart = high_resolution_clock::now();
	//// Calculate median value of image
	//sigmaImage->calculateSigma(imageVec);
	//// Write image to file
	//sigmaImage->writePPM("sigmaImage.ppm");
	//// Write image information to log
	//getInfo(*sigmaImage, "sigmaImage");
	//// Stop Timer
	//epochEnd = high_resolution_clock::now();
	//// Calculate start and stop difference
	//calculateEpoch(epochStart, epochEnd);
	////Delete allocated memory for Sigma Image pointer
	//delete sigmaImage;


	//// Delete and free up memory used by Image* vector
	//for (vector<Image*>::iterator it = imageVec.begin(); it != imageVec.end(); it++) {
	//delete *it;
	//}

	////// Clear Image vector as it is no longer using memory
	////imageVec.clear();
	////// Retrieve memory allocated to Image vector
	////imageVec.shrink_to_fit();

	//// Create new scaled image for x2 zoom
	//ScaledImage *timesTwoImage = new ScaledImage(1500, 1500);
	//// Start Timer
	//epochStart = high_resolution_clock::now();
	//// Read in the image file
	//timesTwoImage->readPPM("Images/Zoom/zIMG_1.ppm");
	//// Scale image
	//timesTwoImage->scaleNearestNeighbour(2);
	//// Write image to file
	//timesTwoImage->writePPM("NearestNeighbourX2.ppm");
	//// Write image information to log
	//getInfo(*timesTwoImage, "NearestNeighbourX2");
	//// Stop Timer
	//epochEnd = high_resolution_clock::now();
	//// Calculate start and stop difference
	//calculateEpoch(epochStart, epochEnd);
	////Delete allocated memory for x2 Image pointer
	//delete timesTwoImage;


	//// Create new scaled image for x2 zoom
	//ScaledImage *timesFourImage = new ScaledImage(3000, 3000);
	//// Start Timer
	//epochStart = high_resolution_clock::now();
	//// Read in the image file
	//timesFourImage->readPPM("Images/Zoom/zIMG_1.ppm");
	//// Scale image
	//timesFourImage->scaleNearestNeighbour(4);
	//// Write image to file
	//timesFourImage->writePPM("NearestNeighbourX4.ppm");
	//// Write image information to log
	//getInfo(*timesFourImage, "NearestNeighbourX4");
	//// Stop Timer
	//epochEnd = high_resolution_clock::now();
	//// Calculate start and stop difference
	//calculateEpoch(epochStart, epochEnd);
	////Delete allocated memory for x2 Image pointer
	//delete timesFourImage;

	//// Create new scaled image for x2 zoom
	//ScaledImage *bilinearImage = new ScaledImage(1500, 1500);
	//// Start Timer
	//epochStart = high_resolution_clock::now();
	//// Read in the image file
	//bilinearImage->readPPM("Images/Zoom/zIMG_1.ppm");
	//// Scale image
	//bilinearImage->scaleBilinear(2);
	//// Write image to file
	//bilinearImage->writePPM("BilinearImage.ppm");
	//// Write image information to log
	//getInfo(*bilinearImage, "BilinearImage");
	//// Stop Timer
	//epochEnd = high_resolution_clock::now();
	//// Calculate start and stop difference
	//calculateEpoch(epochStart, epochEnd);
	////Delete allocated memory for x2 Image pointer
	//delete bilinearImage;
	

	// Region of Interest
	Image *regionDefaultImage = new Image(4592, 3056);
	regionDefaultImage->readPPM("Images/ImageStacker_set2/IMG_4.ppm");
	Image *extractedImage = new Image(500, 500);
	extractedImage = regionDefaultImage->regionOfInterest(4154600, 500);
	extractedImage->writePPM("RegionOfInterest.ppm");

	delete regionDefaultImage;
	delete extractedImage;

	ScaledImage *scaleRegion = new ScaledImage(1000,1000);
	scaleRegion->readPPM("RegionOfInterest.ppm");
	scaleRegion->scaleNearestNeighbour(2);
	scaleRegion->writePPM("RegionOfInterestX2.ppm");
	
	delete scaleRegion;

	ScaledImage *scaleRegionFour = new ScaledImage(2000, 2000);
	scaleRegionFour->readPPM("RegionOfInterest.ppm");
	scaleRegionFour->scaleNearestNeighbour(4);
	scaleRegionFour->writePPM("RegionOfInterestX4.ppm");

	delete scaleRegionFour;

	//Prevents auto close.
	int endbreak;
	cout << "End of Program. Press any key to continue" << endl;
	cin >> noskipws >> endbreak;
	return 0;
}