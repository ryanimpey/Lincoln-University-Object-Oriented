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

Image::Rgb::Rgb() {
	r = 0;
	g = 0;
	b = 0;
}

Image::Rgb::Rgb(float c) {
	r = c;
	b = c;
	g = c;
}

Image::Rgb::Rgb(float _r, float _g, float _b) {
	r = _r;
	g = _g;
	b = _b;
}

bool Image::Rgb::operator!= (const Rgb &c) {
	return c.r != r || c.g != g || c.b != b;
}

Image::Rgb& Image::Rgb::operator*= (const Rgb &rgb) {
	r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
}

Image::Rgb& Image::Rgb::operator/= (const int val) {
	r /= val, g /= val, b /= val; return *this;
}

Image::Rgb& Image::Rgb::operator+= (const Rgb &rgb) {
	r += rgb.r, g += rgb.g, b += rgb.b; return *this;
}

Image::Rgb& Image::Rgb::operator -= (const Rgb &rgb) {
	r -= rgb.r, g -= rgb.g, b -= rgb.b; return *this;
}

float& operator+= (float &f, const Image::Rgb rgb) {
	f += (rgb.r + rgb.g + rgb.b) / 3.f; return f;
}

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

//RGB const ops
const Image::Rgb& Image::operator[](const unsigned int &i) const {
	return pixels[i];
}

Image::Rgb& Image::operator[] (const unsigned int &i) {
	return pixels[i];
}


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
		//src.w = w;
		//src.h = h;\
		//cout << w << " " << h << endl;
		//src.pixels = new Image::Rgb[w * h]; // this is throw an exception if bad_alloc 
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
	//Confirm image read
	//Delete this to prevent multiple lines output
	//cout << "Image read" << endl;
	//return src;
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

void Image::calculateMean(vector<Image>& imageVec) {
	cout << "Calculating Mean..." << endl;
	//Image outputImage(imageVec.at(0).w, imageVec.at(0).h); //Create output image for mean values

	vector<Image>::iterator imageIt; //Create iterator to go through images in vector

	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {
		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); ++imageIt) {
			//Image tempImg = *imageIt; //Create temp image from current image
			pixels[i] += imageIt->pixels[i];

		}
		pixels[i] /= imageVec.size();
	}

	cout << "Mean Calculated!" << endl;
}

void Image::calculateMedian(vector<Image>& imageVec) {
	cout << "Calculating Median..." << endl;
	//Create output image for mean values
	//Image outputImage(imageVec.at(0).w, imageVec.at(0).h);

	//Create iterator to go through images in vector
	vector<Image>::iterator imageIt;

	vector<float> redValues;
	vector<float> greenValues;
	vector<float> blueValues;

	for (int i = 0; i < (imageVec.at(0).h * imageVec.at(0).w); ++i) {

		//Create vector to store pixel values for each image
		//vector<vector<float>> imageMedian;

		//int iterator = 0;
		for (imageIt = imageVec.begin(); imageIt != imageVec.end(); ++imageIt) {
			//Image tempImg = *imageIt;

			redValues.push_back(imageIt->pixels[i].r);
			greenValues.push_back(imageIt->pixels[i].g);
			blueValues.push_back(imageIt->pixels[i].b);

			//redValues[iterator] = tempImg.pixels[i].r;
			//greenValues[iterator] = tempImg.pixels[i].g;
			//blueValues[iterator] = tempImg.pixels[i].b;

			//iterator++;

			//imageMedian.push_back({ tempImg.pixels[i].r , tempImg.pixels[i].g, tempImg.pixels[i].b });

		}

		//Sort the imageMedian vector, required to find median value.

		sort(redValues.begin(), redValues.end());
		sort(greenValues.begin(), greenValues.end());
		sort(blueValues.begin(), blueValues.end());

		pixels[i].r = redValues[6];
		pixels[i].g = greenValues[6];
		pixels[i].b = blueValues[6];

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

void Image::calculateSigma(vector<Image>& imageVec) {
		cout << "Calculating Sigma..." << endl;
		//Image medianImage = medianImagei; //Take input image
		//Image standardImage = standardImagei; //Take input image
		//If image is less than median - (1*sd) or greater than median + (1*sd)
		//do this for each image, if the image pixel value is not in boundaries then remove it
		//for 13 images, in their own rgb array, if the value in that array is less than the one made by median[i] +/- standardImage[i] then remove it, loop with function overloading
		
		vector<Image>::iterator ivi;
		//Image outputImage(imageVec.at(0).w, imageVec.at(0).h);
	
		vector<float> redVals;
		vector<float> greenVals;
		vector<float> blueVals;

		for (int i = 0; i < (imageVec.at(0).w * imageVec.at(0).h); ++i) {
	
			for (ivi = imageVec.begin(); ivi != imageVec.end(); ivi++) {
				
				redVals.push_back(ivi->pixels[i].r);
				
				greenVals.push_back(ivi->pixels[i].g);
				
				blueVals.push_back(ivi->pixels[i].b);
			}
	
			//float redMed = calculateMedian(redVals), redSta = calculateStandard(redVals);
			//float greenMed = calculateMedian(greenVals), greenSta = calculateStandard(greenVals);
			//float blueMed = calculateMedian(blueVals), blueSta = calculateStandard(blueVals);
	
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

Image::~Image() {
	//if (pixels != NULL) delete[] pixels;
	//delete[] pixels;
}


//Image::Image(const unsigned int _w, const unsigned int _h, const Rgb &c) {
//	w = _w;
//	h = _h;
//	pixels = NULL;
//
//	pixels = new Rgb[w * h];
//	for (int i = 0; i < w * h; ++i)
//		pixels[i] = c;
//}

ScaledImage::ScaledImage(const unsigned int &_w, const unsigned int &_h, const Rgb &c) : Image(_w, _h, c) {}

void ScaledImage::scaleNearestNeighbour(int amount) {

	cout << "Scaling image by " << amount << "..." << endl;

	int w1 = w / amount;
	int w2 = w;
	int h1 = h / amount;
	int h2 = h;

	Image *outputImage = new Image(w2, h2);

	float x_ratio = (float)w1 / w2;
	float y_ratio = (float)h1 / h2;

	float px;
	float py;

	for (int i = 0; i < h2; i++) {
		for (int j = 0; j < w2; j++) {
			px = floor(j*x_ratio);
			py = floor(i*y_ratio);
			outputImage->pixels[(i*w2) + j] = pixels[(int)((py*w1) + px)];
		}
	}

	cout << "Done!" << endl;

	pixels = outputImage->pixels;
	delete outputImage;

}

void Image::imageInformation(string filename) {

	ifstream ifs; // Input file stream
	string imageFileName = filename + ".ppm";
	ifs.open(imageFileName, ios::binary); // Open the file passed in

	int currentLine = 0; // Keep track of what line the program is currently on
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

void ScaledImage::imageInformation(string filename) {

	ifstream ifs; // Input file stream
	string imageFileName = filename + ".ppm";
	ifs.open(imageFileName, ios::binary); // Open the file passed in

	int currentLine = 0; // Keep track of what line the program is currently on
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
		ofs << "\r\nOriginal Image size: 750px * 750px \r\n";
		ofs << "New image size: " << 750 * (w/ 750) << "px * " << 750 * (w / 750) << "px";
	}

	ofs.close(); //Close file stream

	cout << "Log file for " << filename << " created: " << logFileName << endl;

}