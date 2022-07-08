#include "Bitmap.h"
#include"BitmapFileHeaders.h"
#include"BitmapInfoHeaders.h"
#include<fstream>
	//Bitmap class
using namespace std;

Bitmap::Bitmap(int width, int height) : width(width), height(height), Pixel(new uint8_t[width * height * 3]{})
	{

	}
	bool Bitmap::write(string filename) {
		 
		BitmapFileHeader FileHeader;
		BitmapInfoHeader InfoHeader;

		FileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (width * height * 3);
		FileHeader.dataOffSet = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		InfoHeader.width = width;
		InfoHeader.height = height;

		FileHeader.header[0] = 'B';
		FileHeader.header[1] = 'M';
		ofstream file;
		file.open(filename, ios::out | ios::binary);//our file "filename" which gonna contain a bitmap for us
		if (!file) {

			return false;
		}
		file.write((char*)&(FileHeader), sizeof(FileHeader));
		file.write((char*)&(InfoHeader), sizeof(InfoHeader));
		file.write((char*)Pixel.get(), (width * height*3));

		file.close();
		if (!file) {

			return false;
		}
		return true;
	}
	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		uint8_t* pPixel = Pixel.get();
		pPixel += (y * 3) * width + (x * 3);
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
		
	}
	Bitmap::~Bitmap() {};

