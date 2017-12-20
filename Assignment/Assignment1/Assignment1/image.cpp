#include "image.h"
#include <cstdlib> 
#include <cstdio> 
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "calculations.h"

using namespace std;
using namespace std::chrono;

/* --- Image Class --- */

// Empty RGB Constructor
Image::Rgb::Rgb() {
	r = 0;
	g = 0;
	b = 0;
}

// RGB constructor with a single arguement
Image::Rgb::Rgb(float c) {
	// Set the rgb values equal to the parameter c
	r = c;
	b = c;
	g = c;
}

Image::Rgb::Rgb(float _r, float _g, float _b) {
	// Set the rgb values equal to the parameter _r, _g, and _b
	r = _r;
	g = _g;
	b = _b;
}

// != Operator overload for comparing Rgb's
bool Image::Rgb::operator!= (const Rgb &c) {
	return c.r != r || c.g != g || c.b != b;
}

// *= Operator overload for multiplying Rgb's
Image::Rgb& Image::Rgb::operator*= (const Rgb &rgb) {
	r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
}

// /= Operator overload for dividing Rgb's
Image::Rgb& Image::Rgb::operator/= (const int val) {
	r /= val, g /= val, b /= val; return *this;
}

// += Operator overload for adding Rgb's
Image::Rgb& Image::Rgb::operator+= (const Rgb &rgb) {
	r += rgb.r, g += rgb.g, b += rgb.b; return *this;
}

// -= Operator overload for subtracting Rgb's
Image::Rgb& Image::Rgb::operator -= (const Rgb &rgb) {
	r -= rgb.r, g -= rgb.g, b -= rgb.b; return *this;
}

// * Operator overload for multiplying Rgb's
Image::Rgb& Image::Rgb::operator* (const float val) {
	r * val, g * val, b * val; return *this;
}

// += Operator overload for adding Rgb's
Image::Rgb& Image::Rgb::operator+(const Rgb& rgb) {
	r + rgb.r, g + rgb.g, b + rgb.b; return *this;
}

// += Operator overload for adding a float to an Rgb's
float& operator+= (float &f, const Image::Rgb rgb) {
	f += (rgb.r + rgb.g + rgb.b) / 3.f; return f;
}

/* --- Image Constructors --- */
Image::Image() {
	w = 0;
	h = 0;
	Image::Rgb*pixels(nullptr);
}

Image::Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c){
	w = _w;
	h = _h;

	pixels = new Rgb[w * h];
	for (int i = 0; i < w * h; ++i) {
		pixels[i] = c;
	}
}

/* --- End Image Constructors --- */

// Return Image width
int Image::getWidth() {
	return w;
}

// Return Image height
int Image::getHeight() {
	return h;
}

//RGB const ops
const Image::Rgb& Image::operator[](const unsigned int &i) const {
	return pixels[i];
}

Image::Rgb& Image::operator[] (const unsigned int &i) {
	return pixels[i];
}

// Read in PPM file
void Image::readPPM(const char *filename) {
	ifstream ifs;
	ifs.open(filename, ios::binary);
	//Image src;
	try {
		if (ifs.fail()) {
			throw("Can't open the input file - is it named correctly/is it in the right directory?");
		}
		string header;
		int w, h, b;
		ifs >> header;
		if (strcmp(header.c_str(), "P6") != 0) throw("Can't read the input file - is it in binary format (Has P6 in the header)?");
		ifs >> w >> h >> b;
		ifs.ignore(256, '\n'); // skip empty lines in necessary until we get to the binary data 
		unsigned char pix[3]; // read each pixel one by one and convert bytes to floats 
		for (int i = 0; i < w * h; ++i) {
			ifs.read(reinterpret_cast<char *>(pix), 3);
			/*src.*/pixels[i].r = pix[0] / 255.f;
			/*src.*/pixels[i].g = pix[1] / 255.f;
			/*src.*/pixels[i].b = pix[2] / 255.f;
		}
		ifs.close();
	}
	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		ifs.close();
	}
}

void Image::writePPM(const char *filename) {
	cout << "Writing image to " << filename << "..." << endl;
	if (w == 0 || h == 0) { fprintf(stderr, "Can't save an empty image\n"); return; }
	ofstream ofs;
	try {
		ofs.open(filename, ios::binary); // need to spec. binary mode for Windows users 
		if (ofs.fail()) throw("Can't open output file");
		ofs << "P6\n" << w << " " << h << "\n255\n";
		//cout << "P6\n" << img.w << " " << img.h << "\n255\n";
		unsigned char r, g, b;
		// loop over each pixel in the image, clamp and convert to byte format
		for (int i = 0; i < w * h; ++i) {
			r = static_cast<unsigned char>(min(1.f, pixels[i].r) * 255);
			g = static_cast<unsigned char>(min(1.f, pixels[i].g) * 255);
			b = static_cast<unsigned char>(min(1.f, pixels[i].b) * 255);
			ofs << r << g << b;
		}
		ofs.close();
		//Confirm image write moved to individual methods
	}
	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		ofs.close();
	}

	cout << "Finished writing " << filename << "!" << endl;
}

// Calculate mean value of an image set
void Image::calculateMean(vector<Image*>& imageVec) {
	cout << "Calculating Mean..." << endl;

	//Create iterator to go through images in vector
	vector<Image*>::iterator imageIt; 

	// For every pixel in the input images
	for (int i = 0; i < (imageVec.at(0)->getHeight() * imageVec.at(0)->getWidth()); ++i) {
		// For every Image in the Image vector
		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); ++imageIt) {
			// Add the value in the current images pixel to the overall sum of pixels
			pixels[i] += (*imageIt)->pixels[i];
		}
		// Divide the pixel amount by the size of the Image vector
		pixels[i] /= imageVec.size();
	}

	cout << "Mean Calculated!" << endl;
}

// Calculate median value of an image set
void Image::calculateMedian(vector<Image*>& imageVec) {
	cout << "Calculating Median..." << endl;

	// Create iterator to go through images in vector
	vector<Image*>::iterator imageIt;

	// Vectors to hold RGB values
	vector<float> redValues;
	vector<float> greenValues;
	vector<float> blueValues;

	for (int i = 0; i < (imageVec.at(0)->getHeight() * imageVec.at(0)->getWidth()); ++i) {

		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); ++imageIt) {
			// Push back values to respective vectors
			redValues.push_back((*imageIt)->pixels[i].r);
			greenValues.push_back((*imageIt)->pixels[i].g);
			blueValues.push_back((*imageIt)->pixels[i].b);
		}

		// Call calculateMedians to calculate median float value
		pixels[i].r = calculateMedians(redValues);
		pixels[i].g = calculateMedians(greenValues);
		pixels[i].b = calculateMedians(blueValues);

		//Clear vectors to remove values but preserve memory allocation
		redValues.clear();
		greenValues.clear();
		blueValues.clear();
	}

	//Release memory
	redValues.shrink_to_fit();
	greenValues.shrink_to_fit();
	blueValues.shrink_to_fit();
	cout << "Median Calculated!" << endl;
}

void Image::calculateSigma(vector<Image*>& imageVec) {
		cout << "Calculating Sigma..." << endl;
		
		// Iterator for vector
		vector<Image*>::iterator ivi;
		
		// Vectors to hold RGB values
		vector<float> redVals;
		vector<float> greenVals;
		vector<float> blueVals;

		for (int i = 0; i < (imageVec.at(0)->getWidth() * imageVec.at(0)->getHeight()); ++i) {
	
			for (ivi = imageVec.begin(); ivi != imageVec.end(); ivi++) {
				//For every pixel, then for every image...

				// Push back values to respective vectors
				redVals.push_back((*ivi)->pixels[i].r);
				greenVals.push_back((*ivi)->pixels[i].g);
				blueVals.push_back((*ivi)->pixels[i].b);
			}
	
			// Call calculateSingleSigma to calculate sigma value
			pixels[i].r = calculateSingleSigma(redVals);
			pixels[i].g = calculateSingleSigma(greenVals);
			pixels[i].b = calculateSingleSigma(blueVals);
			
			//Clear vectors to remove values but preserve memory allocation
			redVals.clear();
			greenVals.clear();
			blueVals.clear();
	
		}

		//Release memory
		redVals.shrink_to_fit();
		greenVals.shrink_to_fit();
		blueVals.shrink_to_fit();

		cout << "Sigma Calculated!" << endl;
		//return outputImage;
	
}

// Get Image Information
void Image::imageInformation(string filename) {
	// Input file stream
	ifstream ifs;
	string imageFileName = filename + ".ppm";
	// Open the file passed in
	ifs.open(imageFileName, ios::binary);

	// Keep track of what line the program is currently on
	int currentLine = 0;
	string line; // The contents of that line
	array<string, 3> outputInformation = {}; // Vector to hold file information

	if (ifs.is_open()) {
		while (getline(ifs, line) && currentLine < 3) {
			outputInformation[currentLine] = line;
			currentLine++;
		}
	}

	ifs.close();

	ofstream ofs; // Output file stream
	string logFileName = filename + "Log.txt";
	ofs.open(logFileName, ios::binary);

	if (ofs.fail()) throw("Can't open output file"); // Check file can be opened

	if (ofs.is_open()) {

		ofs << "Image Filename: " << imageFileName << ".\r\n"; // Write image file name to log
		ofs << "Log Filename: " << logFileName << "\r\n"; // Write log file name to log
		ofs << "Binary Magic Number of PPM file: " << outputInformation[0] << ".\r\n"; //Output image magic number (P6)
		ofs << "Image Height and Width: " << outputInformation[1] << ".\r\n";
		ofs << "Maximum colour value: " << outputInformation[2] << ".\r\n";
		ofs << "This .PPM file is in binary and is using 24 bits per pixel. (8 for R, 8 for G, and 8 for B).\r\n";

		auto timeNow = time(nullptr); //Get current time
		auto timeLocal = *localtime(&timeNow); // Convert time into a usable local time format for parsing later

		ofs << "Log file created at: " << put_time(&timeLocal, "%F, %T"); // Output time image and log file created at
	}

	ofs.close(); //Close file stream

	cout << "Log file for " << filename << " created: " << logFileName << endl;

}

Image* Image::regionOfInterest(int pixel, int dimension) {

	Image *outputImage = new Image(dimension, dimension);

	int iterations = 0;
	int pixelVal = 0;
	for (int i = pixel; i < h*w;) {

		outputImage->pixels[pixelVal] = pixels[i];
		//cout << "PixelVal: " << pixelVal << ", I: " << i << endl;

		pixelVal++;

		if (i < ((iterations * w) + (pixel + dimension))) {
			i++;
		}
		else {
			iterations++;
			i = (iterations * w) + pixel + 1;
		}


		if (pixelVal > dimension*dimension) {
			break;
		}

	}

	return outputImage;
}

// Image destructor
Image::~Image() {
	if (pixels != NULL) delete[] pixels;
	//delete[] pixels;
}

/* --- End Image Class --- */

/* --- ScaledImage Class --- */

// Scaled Image constructor
ScaledImage::ScaledImage(const unsigned int &_w, const unsigned int &_h, const Rgb &c) : Image(_w, _h, c) {}

// Scaled image destructor
ScaledImage::~ScaledImage() {

}

// Nearest Neighbour Scaling
void ScaledImage::scaleNearestNeighbour(int amount) {

	cout << "Scaling image by " << amount << "..." << endl;

	// Original image width
	int w1 = getWidth() / amount;
	// Scaled image width
	int w2 = getWidth();
	// Original image height
	int h1 = getHeight() / amount;
	// Scaled image height
	int h2 = getHeight();

	// Create image to store new image contents
	Image *outputImage = new Image(w2, h2);

	// Calculate x and y ratios
	float x_ratio = (float)w1 / w2;
	float y_ratio = (float)h1 / h2;

	// Store values of pixel X and pixel Y
	float px;
	float py;

	for (int i = 0; i < h2; i++) {
		for (int j = 0; j < w2; j++) {
			// Pixel X equals the floored value of the current j pixel (width e.g 15th pixel) * the x_ratio
			px = floor(j*x_ratio);
			// Pixel Y equals the floored value of the current i pixel (width e.g 15th pixel) * the y_ratio
			py = floor(i*y_ratio);
			// The value at (height pixel (e.g 15th pixel) * the new width = pixel Y value * original width + pixelX value
			outputImage->pixels[(i*w2) + j] = pixels[(int)((py*w1) + px)];
		}
	}

	cout << "Nearest Neighbour Scaling Complete!" << endl;

	// Set pixels equal to the output image value.
	pixels = outputImage->pixels;
}

// Get Image Information (Polymorphism) 
void ScaledImage::imageInformation(string filename) {
	// Input filestream
	ifstream ifs;
	string imageFileName = filename + ".ppm";
	// Open the file passed in
	ifs.open(imageFileName, ios::binary);

	// Keep track of what line the program is currently on
	int currentLine = 0;
	// The contents of that line
	string line;
	// Vector to hold file information
	array<string, 3> outputInformation = {};

	//Check if the file is open
	if (ifs.is_open()) {
		//If so, read the line that includes image stats (PPM exclusive)
		while (getline(ifs, line) && currentLine < 3) {
			outputInformation[currentLine] = line;
			currentLine++;
		}
	}

	// Close filestream
	ifs.close();

	// Output file stream
	ofstream ofs;
	string logFileName = filename + "Log.txt";
	ofs.open(logFileName, ios::binary);

	// Check file can be opened
	if (ofs.fail()) throw("Can't open output file");

	// Check stream is open
	if (ofs.is_open()) {

		ofs << "Image Filename: " << imageFileName << ".\r\n"; // Write image file name to log
		ofs << "Log Filename: " << logFileName << "\r\n"; // Write log file name to log
		ofs << "Binary Magic Number of PPM file: " << outputInformation[0] << ".\r\n"; //Output image magic number (P6)
		ofs << "Image Height and Width: " << outputInformation[1] << ".\r\n"; // Output height and width
		ofs << "Maximum colour value: " << outputInformation[2] << ".\r\n"; // Output colour value
		ofs << "This .PPM file is in binary and is using 24 bits per pixel. (8 for R, 8 for G, and 8 for B).\r\n"; // Output PPM info

		auto timeNow = time(nullptr); //Get current time
		auto timeLocal = *localtime(&timeNow); // Convert time into a usable local time format for parsing later

		ofs << "Log file created at: " << put_time(&timeLocal, "%F, %T"); // Output time image and log file created at
		ofs << "\r\nOriginal Image size: 750px * 750px \r\n"; // Output image scaling stats
		ofs << "New image size: " << 750 * (getWidth()/ 750) << "px * " << 750 * (getWidth() / 750) << "px"; // Output image scaling stats
	}

	//Close file stream
	ofs.close();

	cout << "Log file for " << filename << " created: " << logFileName << endl;

}

void ScaledImage::scaleBilinear(int amount) {

	cout << "Scaling image using bilinear by" << amount << "..." << endl;

	// Original image width
	int w1 = getWidth() / amount;
	// New image width
	int w2 = getWidth();
	// Original image height
	int h1 = getHeight() / amount;
	// New image height
	int h2 = getHeight();

	// Output image
	Image *outputImage = new Image(w2, h2);

	// Create int values for pixel locations
	int x, y, index;

	// Calculate X and Y ratios
	float x_ratio = ((float)(w1 - 1)) / w2;
	float y_ratio = ((float)(h1 - 1)) / h2;

	// Create floats to hold values including pixel difference and RGB specific values
	float x_diff, y_diff, blue, red, green;

	// Offset to store current pixel
	int offset = 0;

	for (int i = 0; i<h2; i++) {
		for (int j = 0; j<w2; j++) {
			// Set X and Y equal to ratio * the current height OR width value
			x = (int)(x_ratio * j);
			y = (int)(y_ratio * i);			x_diff = (x_ratio * j) - x;
			y_diff = (y_ratio * i) - y;
			index = y*w1 + x;

			// Set the red pixel value. This is the same as r(1-w)(1-h) + r(w)(1-h) + r(h)(1-w) + r(w*h) (Tech-Algorithm)
			red = (pixels[index].r)*(1 - x_diff)*(1 - y_diff) + (pixels[index + 1].r)*(x_diff)*(1 - y_diff) +
				(pixels[index + w1].r)*(y_diff)*(1 - x_diff) + (pixels[index + w1 + 1].r)*(x_diff*y_diff);

			// Set the green pixel value. This is the same as g(1-w)(1-h) + g(w)(1-h) + g(h)(1-w) + g(w*h) (Tech-Algorithm)
			green = (pixels[index].g)*(1 - x_diff)*(1 - y_diff) + (pixels[index + 1].g)*(x_diff)*(1 - y_diff) +
				(pixels[index + w1].g)*(y_diff)*(1 - x_diff) + (pixels[index + w1 + 1].g)*(x_diff*y_diff);

			// Set the blue pixel value. This is the same as b(1-w)(1-h) + b(w)(1-h) + b(h)(1-w) + b(w*h) (Tech-Algorithm)
			blue = (pixels[index].b)*(1 - x_diff)*(1 - y_diff) + (pixels[index + 1].b)*(x_diff)*(1 - y_diff) +
				(pixels[index + w1].b)*(y_diff)*(1 - x_diff) + (pixels[index + w1 + 1].b)*(x_diff*y_diff);

			// Set the output image pixel equal to the previously calculated values
			outputImage->pixels[offset].r = red;
			outputImage->pixels[offset].g = green;
			outputImage->pixels[offset].b = blue;
			offset++;
		}
	}

	// Set the input image equal to the created outputImage
	pixels = outputImage->pixels;
	cout << "Bilinear scaling complete!" << endl;

}

/* --- End ScaledImage Class --- */