#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include "calculations.h"

using namespace std;

float calculateMean(vector<float> &floatVec) {
	float meanValue = 0;
	vector<float>::iterator fi;
	for (fi = floatVec.begin(); fi != floatVec.end(); fi++) {
		meanValue += *fi;
	}

	meanValue /= floatVec.size();

	return meanValue;
}

float calculateMedian(vector<float> &floatVec) {

	sort(floatVec.begin(), floatVec.end());
	
	float medianValue = 0; //Create value for median
	if (floatVec.size() % 2 == 0 ) {
		medianValue = (floatVec.at(floatVec.size() / 2) + floatVec.at((floatVec.size() / 2) - 1)) / 2;
	} else{
		medianValue = floatVec.at(floatVec.size() / 2);
	}

	return medianValue;

}

//Image calculateStandard(vector<Image> imageVec) {
//	Image meanImage = calculateMean(imageVec); //Get mean image values using previously defined method
//	Image standardImage(imageVec.at(0).w, imageVec.at(0).h); //Create image to push standard values to
//
//	cout << "calculating standard" << endl;
//	vector<Image> standardVector = imageVec; // Create standard vector for calculations
//	vector<Image>::iterator svi;
//	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {
//		for (svi = standardVector.begin(); svi != standardVector.end(); svi++) {
//			Image temp = *svi; // Create temp image to hold current vector image
//
//			/*if (i == 200) {
//				cout << "Original value: " << temp.pixels[i].r << endl;
//			}*/
//
//			temp.pixels[i] -= meanImage.pixels[i]; //Minus the mean from each pixel
//			temp.pixels[i] *= temp.pixels[i]; //Square the result
//
//			standardImage.pixels[i] += temp.pixels[i];
//
//		}
//
//		/*if (i == 200) {
//			cout << "Standard image total: " << standardImage.pixels[i].r << endl;
//		}*/
//		standardImage.pixels[i] /= imageVec.size();
//
//
//		/*if (i == 200) {
//			cout << "Standard value divided by " << imageVec.size() << ": " << standardImage.pixels[i].r << endl;
//		}*/
//
//		standardImage.pixels[i].r = sqrt(standardImage.pixels[i].r);
//		standardImage.pixels[i].g = sqrt(standardImage.pixels[i].g);
//		standardImage.pixels[i].b = sqrt(standardImage.pixels[i].b);
//
//		/*if (i == 200) {
//			cout << "Standard value square rooted: " << standardImage.pixels[i].r << endl;
//		}*/
//
//	}
//	cout << "standard calculated" << endl;
//	return standardImage;
//
//}

float calculateStandard(vector<float> &floatVec) {
	float outputValue = 0;
	float meanValue = calculateMean(floatVec);
	vector<float>::iterator fi;

	for (fi = floatVec.begin(); fi != floatVec.end(); fi++) {
		float temp = *fi - meanValue;
		temp *= temp;

		outputValue +=temp;
	}

	outputValue /= floatVec.size();
	outputValue = sqrt(outputValue);

	return outputValue;

}
//
//Image calculateSigma(vector<Image> &imageVec) {
//	cout << "Sigma started" << endl;
//	//Image medianImage = medianImagei; //Take input image
//	//Image standardImage = standardImagei; //Take input image
//	//If image is less than median - (1*sd) or greater than median + (1*sd)
//	//do this for each image, if the image pixel value is not in boundaries then remove it
//	//for 13 images, in their own rgb array, if the value in that array is less than the one made by median[i] +/- standardImage[i] then remove it, loop with function overloading
//	
//	vector<Image>::iterator ivi;
//	Image outputImage(imageVec.at(0).w, imageVec.at(0).h);
//
//	for (int i = 0; i < (imageVec.at(0).w * imageVec.at(0).h); ++i) {
//
//		vector<float> redVals;
//		vector<float> greenVals;
//		vector<float> blueVals;
//
//		for (ivi = imageVec.begin(); ivi != imageVec.end(); ivi++) {
//			Image temp = *ivi;
//			
//			redVals.push_back(temp.pixels[i].r);
//			
//			greenVals.push_back(temp.pixels[i].g);
//			
//			blueVals.push_back(temp.pixels[i].b);
//		}
//
//		//float redMed = calculateMedian(redVals), redSta = calculateStandard(redVals);
//		//float greenMed = calculateMedian(greenVals), greenSta = calculateStandard(greenVals);
//		//float blueMed = calculateMedian(blueVals), blueSta = calculateStandard(blueVals);
//
//		outputImage.pixels[i].r = calculateSingleSigma(redVals);
//		outputImage.pixels[i].g = calculateSingleSigma(greenVals);
//		outputImage.pixels[i].b = calculateSingleSigma(blueVals);
//
//		redVals.clear();
//		greenVals.clear();
//		blueVals.clear();
//
//	}
//	cout << "sigma complete." << endl;
//	return outputImage;
//
//}

float calculateSingleSigma(vector<float> &floatVec, float loops) {
	//vector<float> outputVec;
	vector<float>::iterator fi;
	float median = calculateMedian(floatVec);
	float standard = calculateStandard(floatVec);

	for (fi = floatVec.begin(); fi != floatVec.end();) {
		double value = *fi - (median + standard);
		if ((*fi < (median - standard)) || (*fi> (median + standard))) {
			fi = floatVec.erase(fi);
		}
		else {
			++fi;
		}
	}

	if (floatVec.size() <= 2) {
		float outputValue = 0;
		sort(floatVec.begin(), floatVec.end());

		if (floatVec.size() % 2 == 0) {
			outputValue = (floatVec.at(floatVec.size() / 2) + floatVec.at((floatVec.size() / 2) - 1)) / 2;
		}
		else {
			outputValue = floatVec.at(floatVec.size() / 2);
		}

		return outputValue;
	}

	if (loops < 5) {
		loops++;
		return calculateSingleSigma(floatVec, loops);
	}
	else {

		float outputValue = 0;
		sort(floatVec.begin(), floatVec.end());

		if (floatVec.size() % 2 == 0) {
			outputValue = (floatVec.at(floatVec.size() / 2) + floatVec.at((floatVec.size() / 2) - 1)) / 2;
		}
		else {
			outputValue = floatVec.at(floatVec.size() / 2);
		}

		return outputValue;

	}

}

void calculateEpoch(high_resolution_clock::time_point start, high_resolution_clock::time_point end) {
	//Transform times from epoch to milliseconds for human readability
	auto epochStartToMS = start.time_since_epoch();
	auto epochEndToMS = end.time_since_epoch();

	//Minus the difference between the two to get a value in ms.
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(epochEndToMS - epochStartToMS).count();
	cout << "File created in " << millis << "ms.\n---------- " << endl;
}