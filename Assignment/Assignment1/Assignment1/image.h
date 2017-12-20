#pragma once
#pragma warning(disable : 4996)
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
#include <vector>

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
		Rgb& operator /= (const int);
		Rgb& operator -= (const Rgb &rgb);
		Rgb& operator * (const float);
		Rgb& operator + (const Rgb& rgb);
		friend float& operator += (float &f, const Rgb rgb);
		float r, g, b;
	};

	Image();
	Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);
	const Rgb& operator [] (const unsigned int &i) const;
	Rgb& operator [] (const unsigned int &i);

	void readPPM(const char *filename); // Read in an image file
	void writePPM(const char *filename); // Write out data to an image file
	void calculateMean(vector<Image*> &imageVec); // Calculate the mean value of a set of images
	void calculateMedian(vector<Image*> &imageVec); // Calculate the median value of a set of images
	void calculateSigma(vector<Image*> &imageVec); // Calculate the sigma value of a set of images
	virtual void imageInformation(string); // Write information about the image to a log file, virtual for polymorphism
	Image* regionOfInterest(int, int); // Collect a region of interest from the file

	~Image(); // Image destructor

	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors
	Rgb *pixels; // 1D array of pixels
	int getWidth(); // Return width of image
	int getHeight(); // Return height of image
private:
	unsigned int w, h; // Image resolution 
};

class ScaledImage : public Image {
public:
	ScaledImage(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);
	void scaleNearestNeighbour(int); // Scale image using Nearest-Neighbour
	void scaleBilinear(int); // Scale image using Bilinear
	void imageInformation(string); // Write information about the image to a log file using virtual function previously defined

	~ScaledImage(); // Image destructor

};