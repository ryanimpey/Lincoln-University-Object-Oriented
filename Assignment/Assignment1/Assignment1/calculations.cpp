#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include "calculations.h"

using namespace std;

// Calculate mean for a vector of floats
float calculateMean(vector<float> &floatVec) {
	// Create variable to hold mean result 
	float meanValue = 0;
	// Float iterator to iterator through floatVec
	vector<float>::iterator fi;
	for (fi = floatVec.begin(); fi != floatVec.end(); fi++) {
		// For every value in the vector, add it to the current value of meanValue
		meanValue += *fi;
	}

	// Divide the sum by the amount to get the average
	meanValue /= floatVec.size();

	// Return mean result variable previously created
	return meanValue;
}

// Calculate median for a vector of floats
float calculateMedians(vector<float> &floatVec) {
	// Sort all floats in the float vector
	sort(floatVec.begin(), floatVec.end());
	
	//Create variable to hold median result
	float medianValue = 0;

	if (floatVec.size() % 2 == 0 ) {
		// If the vector size is even, then add the two middle values together and divide by 2 to get the median value
		medianValue = (floatVec.at(floatVec.size() / 2) + floatVec.at((floatVec.size() / 2) - 1)) / 2;
	} else{
		// Otherwise set the median value equal to the single middle value
		medianValue = floatVec.at(floatVec.size() / 2);
	}

	// Return median result variable previously created
	return medianValue;

}

// Calculate standard deviation for a vector of floats
float calculateStandard(vector<float> &floatVec) {
	// Create variable to hold result
	float outputValue = 0;
	
	// Calculate the mean value of the floatVec input using the previously created function
	float meanValue = calculateMean(floatVec);
	
	// Float iterator to iterate through floatVec
	vector<float>::iterator fi;

	for (fi = floatVec.begin(); fi != floatVec.end(); fi++) {
		// Assign temp to the value located at fi, and subtract the previously calculated mean value
		float temp = *fi - meanValue;
		// Times the temp value by itself to square it
		temp *= temp;

		// Add the temp value to the existing output value
		outputValue +=temp;
	}

	// Divide the output value by the size of the floatVec to get the variance
	outputValue /= floatVec.size();
	// Get the square root value of outputValue to get the standard deviation value
	outputValue = sqrt(outputValue);

	// Return standard deviation value
	return outputValue;

}

// Calculate sigma clipping for a vector of floats
float calculateSingleSigma(vector<float> &floatVec, float loops) {
	// Create iterator to loop through all values of floatVec
	vector<float>::iterator fi;

	// Calculate the median value of floatVec using the previously created function
	float median = calculateMedians(floatVec);
	// Calculate the standard deviation value of floatVec using the previously created function
	float standard = calculateStandard(floatVec);

	// For every float value in the floatVec
	for (fi = floatVec.begin(); fi != floatVec.end();) {

		// Set the value equal to the the value stored at *fi, minus the sum of the median and standard
		double value = *fi - (median + standard);
		
		//If the value at *fi is less than the median - standard, or greater than the median + standard
		if ((*fi < (median - standard)) || (*fi> (median + standard))) {
			// Remove the value from the vector
			fi = floatVec.erase(fi);
		}
		else {
			// Otherwise increment the vector as usual
			++fi;
		}
	}

	// If the vector size is less than or equal to 2
	if (floatVec.size() <= 2) {
		// Create variable to hold output value
		float outputValue = 0;

		// Sort every value remaining in the floatVec
		sort(floatVec.begin(), floatVec.end());

		if (floatVec.size() % 2 == 0) {
			// If the vector size is even, then add the two middle values together and divide by 2 to get the median value
			outputValue = (floatVec.at(floatVec.size() / 2) + floatVec.at((floatVec.size() / 2) - 1)) / 2;
		}
		else {
			// Otherwise set the median value equal to the single middle value
			outputValue = floatVec.at(floatVec.size() / 2);
		}

		// Return the output value
		return outputValue;
	}

	// If the loops variable is less than 5
	if (loops < 5) {
		// Increment the loops variable
		loops++;
		// Recursively call itself passing through the current floatVec and the previously incremented loops value
		return calculateSingleSigma(floatVec, loops);
	}
	// If loops is not less than 5 
	else {
		// Create variable to hold output value
		float outputValue = 0;

		// Sort every value remaining in the floatVec
		sort(floatVec.begin(), floatVec.end());

		if (floatVec.size() % 2 == 0) {
			// If the vector size is even, then add the two middle values together and divide by 2 to get the median value
			outputValue = (floatVec.at(floatVec.size() / 2) + floatVec.at((floatVec.size() / 2) - 1)) / 2;
		}
		else {
			// Otherwise set the median value equal to the single middle value
			outputValue = floatVec.at(floatVec.size() / 2);
		}

		// Return the output value
		return outputValue;
	}

}

// Calculate the run time of a section of code, taking in a start and end time in epoch time
void calculateEpoch(high_resolution_clock::time_point& start, high_resolution_clock::time_point& end) {
	// Calculate the time since epoch for each value
	auto epochStartToMS = start.time_since_epoch();
	auto epochEndToMS = end.time_since_epoch();

	// Minus the difference between the two to get a value in ms.
	auto millis = duration_cast<milliseconds>(epochEndToMS - epochStartToMS).count();
	// Output the result in text form to the console
	cout << "File created in " << millis << "ms.\n---------- " << endl;
}

// Call the imageInformation method for each Image
void getInfo(Image &image, string filename) {

	// Call the imageInformation method
	image.imageInformation(filename);
}