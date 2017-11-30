#include "algorithms.h"
#include <iostream>
#include <array>
#include <algorithm>

Algorithms::Algorithms() {

}

void Algorithms::meanBlend(vector<Image> imageVec) {
	cout << "Beginning Mean File Creation" << endl;

	//Create output image for mean values
	Image outputImage(imageVec.at(0).w, imageVec.at(0).h);

	//Create iterator to go through images in vector
	vector<Image>::iterator imageIt;

	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {
		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); ++imageIt) {
			Image tempImg = *imageIt;
			outputImage.pixels[i].r += tempImg.pixels[i].r;
			outputImage.pixels[i].g += tempImg.pixels[i].g;
			outputImage.pixels[i].b += tempImg.pixels[i].b;

		}
		outputImage.pixels[i].r /= imageVec.size();
		outputImage.pixels[i].g /= imageVec.size();
		outputImage.pixels[i].b /= imageVec.size();
	}


	cout << "Attempting to write mean file..." << endl;
	outputImage.writePPM("meanBlend.ppm");
	cout << "Success! Your image has been saved as meanBlend.ppm" << endl;
}

void Algorithms::medianBlend(vector<Image> imageVec) {
	cout << "Beginning Median File Creation" << endl;

	//Create output image for mean values
	Image outputImage(imageVec.at(0).w, imageVec.at(0).h);

	//Create iterator to go through images in vector
	vector<Image>::iterator imageIt;

	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {

		//Create vector to store pixel values for each image
		vector<vector<float>> imageMedian;

		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); ++imageIt) {
			Image tempImg = *imageIt;

			imageMedian.push_back({ tempImg.pixels[i].r , tempImg.pixels[i].g, tempImg.pixels[i].b});

		}

		//Sort the imageMedian vector, required to find median value.
		sort(imageMedian.begin(), imageMedian.end());
		
		outputImage.pixels[i].r = imageMedian.at(7)[0];
		outputImage.pixels[i].g = imageMedian.at(7)[1];
		outputImage.pixels[i].b = imageMedian.at(7)[2];
	}
	cout << "Attempting to write median file..." << endl;
	outputImage.writePPM("medianBlend.ppm");
	cout << "Success! Your image has been saved as medianBlend.ppm" << endl;
}