#pragma once
#include <vector>
#include "image.h"

using namespace std;

Image calculateMean(vector<Image>);
Image calculateMedian(vector<Image>);
Image calculateStandard(vector<Image>);
Image calculateSigma(vector<Image>);
float calculateMean(vector<float>);
float calculateMedian(vector<float>);
float calculateStandard(vector<float>);
float calculateSingleSigma(vector<float>, float loops = 1);