#pragma pack(2)
#include<cstdint>

struct BitmapFileHeader
{
	char header[2];
	
	int32_t fileSize;
	int32_t reserved{ 0 };
	int32_t dataOffSet;
};