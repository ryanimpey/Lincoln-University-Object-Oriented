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
		Rgb() : r(0), g(0), b(0) {}
		Rgb(float c) : r(c), g(c), b(c) {}
		Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
		bool operator != (const Rgb &c) const
		{
			return c.r != r || c.g != g || c.b != b;
		}
		Rgb& operator *= (const Rgb &rgb)
		{
			r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
		}
		Rgb& operator += (const Rgb &rgb)
		{
			r += rgb.r, g += rgb.g, b += rgb.b; return *this;
		}
		friend float& operator += (float &f, const Rgb rgb)
		{
			f += (rgb.r + rgb.g + rgb.b) / 3.f; return f;
		}
		float r, g, b;
	};

	Image() : w(0), h(0), pixels(nullptr) { /* empty image */ }
	Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack) :
		w(_w), h(_h), pixels(NULL)
	{
		pixels = new Rgb[w * h];
		for (int i = 0; i < w * h; ++i)
			pixels[i] = c;
	}
	const Rgb& operator [] (const unsigned int &i) const
	{
		return pixels[i];
	}
	Rgb& operator [] (const unsigned int &i)
	{
		return pixels[i];
	}

	Image readPPM(const char *filename) {
		//Remove this cout to prevent multiple outputs
		cout << "Reading image ..." << endl;
		ifstream ifs;
		ifs.open(filename, ios::binary);
		Image src;
		try {
			if (ifs.fail()) {
				throw("Can't open the input file - is it named correctly/is it in the right directory?");
			}
			string header;
			int w, h, b;
			ifs >> header;
			if (strcmp(header.c_str(), "P6") != 0) throw("Can't read the input file - is it in binary format (Has P6 in the header)?");
			ifs >> w >> h >> b;
			src.w = w;
			src.h = h;
			//cout << w << " " << h << endl;
			src.pixels = new Image::Rgb[w * h]; // this is throw an exception if bad_alloc 
			ifs.ignore(256, '\n'); // skip empty lines in necessary until we get to the binary data 
			unsigned char pix[3]; // read each pixel one by one and convert bytes to floats 
			for (int i = 0; i < w * h; ++i) {
				ifs.read(reinterpret_cast<char *>(pix), 3);
				src.pixels[i].r = pix[0] / 255.f;
				src.pixels[i].g = pix[1] / 255.f;
				src.pixels[i].b = pix[2] / 255.f;
			}
			ifs.close();
		}
		catch (const char *err) {
			fprintf(stderr, "%s\n", err);
			ifs.close();
		}
		//Confirm image read
		//Delete this to prevent multiple lines output
		cout << "Image read" << endl;
		return src;
	}


	//Write data out to a ppm file
	//Constructs the header as above
	void writePPM(const char *filename)
	{
		//cout << filename << endl;
		cout << "Writing image ..." << endl;
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
			//Confirm image write
			cout << "Image written" << endl;
		}
		catch (const char *err) {
			fprintf(stderr, "%s\n", err);
			ofs.close();
		}
	}

	~Image()
	{
		//if (pixels != NULL) delete[] pixels;
		//delete[] pixels;
	}
	unsigned int w, h; // Image resolution 
	Rgb *pixels; // 1D array of pixels 
	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors 
};

const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);