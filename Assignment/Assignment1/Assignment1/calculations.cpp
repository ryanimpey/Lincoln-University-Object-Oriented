#include "calculations.h"

#include <string>
#include <array>
#include <algorithm>

using namespace std;

Image calculateMean(vector<Image> imageVec) {
	cout << "mean calculate" << endl;
	Image outputImage(imageVec.at(0).w, imageVec.at(0).h); //Create output image for mean values

	vector<Image>::iterator imageIt; //Create iterator to go through images in vector

	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {
		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); ++imageIt) {
			Image tempImg = *imageIt; //Create temp image from current image
			outputImage.pixels[i] += tempImg.pixels[i];

		}
		outputImage.pixels[i] /= imageVec.size();
	}
	cout << "mean calculated" << endl;
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

Image calculateStandard(vector<Image> imageVec) {
	Image meanImage = calculateMean(imageVec); //Get mean image values using previously defined method
	Image standardImage(imageVec.at(0).w, imageVec.at(0).h); //Create image to push standard values to

	vector<Image> standardVector = imageVec; // Create standard vector for calculations
	vector<Image>::iterator svi;
	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {

		for (svi = standardVector.begin(); svi != standardVector.end(); svi++) {
			Image temp = *svi; // Create temp image to hold current vector image

			/*if (i == 200) {
				cout << "Original value: " << temp.pixels[i].r << endl;
			}*/

			temp.pixels[i] -= meanImage.pixels[i]; //Minus the mean from each pixel
			temp.pixels[i] *= temp.pixels[i]; //Square the result

			standardImage.pixels[i] += temp.pixels[i];

		}

		/*if (i == 200) {
			cout << "Standard image total: " << standardImage.pixels[i].r << endl;
		}*/

		standardImage.pixels[i] /= imageVec.size();


		/*if (i == 200) {
			cout << "Standard value divided by " << imageVec.size() << ": " << standardImage.pixels[i].r << endl;
		}*/

		standardImage.pixels[i].r = sqrt(standardImage.pixels[i].r);
		standardImage.pixels[i].g = sqrt(standardImage.pixels[i].g);
		standardImage.pixels[i].b = sqrt(standardImage.pixels[i].b);

		/*if (i == 200) {
			cout << "Standard value square rooted: " << standardImage.pixels[i].r << endl;
		}*/

	}
	int it = 0;
	cin >> noskipws >> it;

	return standardImage;

}

Image calculateSigma(vector<Image>) {
	Image newImage(100,100);
	return newImage;
}