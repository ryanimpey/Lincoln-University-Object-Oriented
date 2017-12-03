#include "calculations.h"

#include <string>
#include <array>
using namespace std;

Image calculateMean(vector<Image> imageVec) {

	Image outputImage(imageVec.at(0).w, imageVec.at(0).h); //Create output image for mean values

	vector<Image>::iterator imageIt; //Create iterator to go through images in vector

	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {
		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); ++imageIt) {
			Image tempImg = *imageIt; //Create temp image from current image
			outputImage.pixels[i] += tempImg.pixels[i];

		}
		outputImage.pixels[i] /= imageVec.size();
	}
	return outputImage;
}

Image calculateMedian(vector<Image> imageVec) {

	//Create output image for mean values
	Image outputImage(imageVec.at(0).w, imageVec.at(0).h);

	//Create iterator to go through images in vector
	vector<Image>::iterator imageIt;

	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {

		//Create vector to store pixel values for each image
		//vector<vector<float>> imageMedian;
		
		array<float, 13> redValues = {};
		array<float, 13> greenValues = {};
		array<float, 13> blueValues = {};

		int iterator = 0;
		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); imageIt++) {
			Image tempImg = *imageIt;
			
			redValues[iterator] = tempImg.pixels[i].r;
			greenValues[iterator] = tempImg.pixels[i].g;
			blueValues[iterator] = tempImg.pixels[i].b;

			iterator++;

			//imageMedian.push_back({ tempImg.pixels[i].r , tempImg.pixels[i].g, tempImg.pixels[i].b });

		}

		//Sort the imageMedian vector, required to find median value.

		sort(redValues.begin(), redValues.end());
		sort(greenValues.begin(), greenValues.end());
		sort(blueValues.begin(), blueValues.end());

		outputImage.pixels[i].r = redValues[6];
		outputImage.pixels[i].g = greenValues[6];
		outputImage.pixels[i].b = blueValues[6];
	}

	return outputImage;
}

Image calculateSigma(vector<Image>) {

}