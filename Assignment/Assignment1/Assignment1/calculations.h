#pragma once
#include <vector>
#include "image.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

float calculateMean(vector<float>&); // Calculate mean for float vector
float calculateMedians(vector<float>&); // Calculate median for float vector
float calculateStandard(vector<float>&); // Calculate standard deviation for float vector
float calculateSingleSigma(vector<float>&, float loops = 1); // Calculate sigma clipping for a float vector
void calculateEpoch(high_resolution_clock::time_point&, high_resolution_clock::time_point&); // Calculate algorithm runtime in milliseconds
void getInfo(Image &image, string); // Retrieve information about an image