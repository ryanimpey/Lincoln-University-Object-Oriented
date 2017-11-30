#include "image.h"
#include <cstdlib> 
#include <cstdio> 
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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

Image::Rgb& Image::Rgb::operator+= (const Rgb &rgb) {
	r += rgb.r, g += rgb.g, b += rgb.b; return *this;
}

float& operator+= (float &f, const Image::Rgb rgb) {
	f += (rgb.r + rgb.g + rgb.b) / 3.f; return f;
}

Image::Image() {
	w = 0;
	h = 0;
	Image::Rgb*pixels(nullptr);
}

//Image::Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c){
//	w = _w;
//	h = _h;
//
//	pixels = new Rgb[w * h];
//	for (int i = 0; i < w * h; ++i) {
//		pixels[i] = c;
//	}
//}

//RGB const ops
const Image::Rgb& Image::operator[](const unsigned int &i) const {
	return pixels[i];
}

Image::Rgb& Image::operator[] (const unsigned int &i) {
	return pixels[i];
}



void Image::readPPM(const char *filename) {
	//Remove this cout to prevent multiple outputs
	cout << "*";
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
		//src.h = h;
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
}

Image::~Image() {
	//if (pixels != NULL) delete[] pixels;
	//delete[] pixels;
}

Image::Image(const unsigned int _w, const unsigned int _h, const Rgb &c) {
	w = _w;
	h = _h;
	pixels = NULL;

	pixels = new Rgb[w * h];
	for (int i = 0; i < w * h; ++i)
		pixels[i] = c;
}