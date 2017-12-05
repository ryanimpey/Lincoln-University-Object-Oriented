#pragma once
#include <vector>
#include "image.h"

using namespace std;

Image calculateMean(vector<Image>);
Image calculateMedian(vector<Image>);
Image calculateStandard(vector<Image>);
vector<Image> calculateSigma(vector<Image>);