#include "calculations.h"

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