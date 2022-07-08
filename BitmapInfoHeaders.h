#pragma once

#include<cstdint>

using namespace std;

struct BitmapInfoHeader {
	int32_t HesderSize{40};
	int32_t width;
	int32_t height;
	int16_t planes{ 1 };
	int16_t bitsPerPixel{ 24 };
	int32_t compreisson{ 0 };
	int32_t dartaSize{ 0 };
	int32_t horizonticalResolution{ 2400 };
	int32_t verticalResolution{ 2400 };
	int32_t colors{ 0 };
	int32_t importantColors{ 0 };

};