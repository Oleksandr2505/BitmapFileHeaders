#pragma once
#include<string>
#include<cstdint>
#include<memory>
using namespace std;
class Bitmap
{
public:
	int height{ 0 };
	int width{ 0 };
	unique_ptr<uint8_t[]> Pixel;
public:
	Bitmap() = default;
	Bitmap(int height, int width);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);//specified the color
	
	bool write(string filename);


		virtual ~Bitmap();
};

