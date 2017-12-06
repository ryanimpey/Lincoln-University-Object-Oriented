#pragma once
#include <vector>
#include "image.h"

using namespace std;

Image calculateMean(vector<Image>);
Image calculateMedian(vector<Image>);
Image calculateStandard(vector<Image>);
float calculateMean(vector<float>);
float calculateMedian(vector<float>);
float calculateStandard(vector<float>);
vector<float> calculateSigma(vector<float>, float, float);
vector<float> calculateSingleSigma(vector<float>, float, float, float loops = 0);