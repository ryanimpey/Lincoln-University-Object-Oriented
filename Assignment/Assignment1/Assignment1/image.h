#pragma once
#pragma once
//*********************************************
//Image class to hold and allow manipulation of images once read into the code
//from https://www.scratchapixel.com/
//*********************************************
#include <cstdlib> 
#include <cstdio> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Image
{
public:
	// Rgb structure, i.e. a pixel 
	struct Rgb
	{
		Rgb();
		Rgb(float c);
		Rgb(float _r, float _g, float _b);
		bool operator != (const Rgb &c);
		Rgb& operator *= (const Rgb &rgb);
		Rgb& operator += (const Rgb &rgb);
		friend float& operator += (float &f, const Rgb rgb);
		float r, g, b;
	};

	Image();
	Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);
	const Rgb& operator [] (const unsigned int &i) const;
	Rgb& operator [] (const unsigned int &i);

	void readPPM(const char *filename);


	//Write data out to a ppm file
	//Constructs the header as above
	void writePPM(const char *filename);

	~Image();

	unsigned int w, h; // Image resolution 
	Rgb *pixels; // 1D array of pixels 
	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors 
};