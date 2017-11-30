#pragma once
#include "image.h"
#include <vector>

using namespace std;

class Algorithms {
public:
	Algorithms();
	void meanBlend(vector<Image>);
	void medianBlend(vector<Image>);
};