#pragma once
#include <vector>
#include "image.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

//Image calculateStandard(vector<Image>);
//Image calculateSigma(vector<Image>&);
float calculateMean(vector<float>&);
float calculateMedian(vector<float>&);
float calculateStandard(vector<float>&);
float calculateSingleSigma(vector<float>&, float loops = 1);
void calculateEpoch(high_resolution_clock::time_point, high_resolution_clock::time_point);