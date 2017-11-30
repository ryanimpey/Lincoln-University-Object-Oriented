#include "algorithms.h"
#include <iostream>

Algorithms::Algorithms() {

}

void Algorithms::meanBlend(vector<Image> imageVec) {

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

	outputImage.writePPM("testPPM.ppm");
}