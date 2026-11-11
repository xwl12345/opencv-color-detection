#include "readImage.h"
int main()
{
	const std::string path = "D:\\VS_Project\\opencv-color-detection\\images\\blue_block.jpg";
	readImage image;
	image.getMat(path);
	return 0;
}