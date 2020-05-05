#include "Map.h"

Surface::Surface(int width, int height)
	: width(width),
	height(height),
	pPixels(new Color[width * height])
{
}

Surface::Surface(int width, int height, Color c)
	: width(width),
	height(height),
	pPixels(new Color[width * height])
{
	for (int i = 0; i < width * height; i++)
	{
		pPixels[i] = c;
	}
}

Surface::Surface(const Surface& surface)
	: Surface(surface.width, surface.height)
{
	const int dimension = width * height;
	for (int i = 0; i < dimension; i++)
	{
		pPixels[i] = surface.pPixels[i];
	}
}

Surface::Surface(std::string filename)
{
	std::ifstream file(filename, std::ios::binary);
	assert(file);

	BITMAPFILEHEADER bmpFileHeader;
	file.read(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));
	BITMAPINFOHEADER bmpFileInfo;
	file.read(reinterpret_cast<char*>(&bmpFileInfo), sizeof(bmpFileInfo));
	assert(bmpFileInfo.biBitCount == 24);
	assert(bmpFileInfo.biCompression == BI_RGB);

	width = bmpFileInfo.biWidth;
	height = bmpFileInfo.biHeight;
	pPixels = new Color[width * height];
	file.seekg(bmpFileHeader.bfOffBits);
	const int padding = (4 - (width * 3) % 4) % 4;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			putPixel(j, i, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}
}

Surface::~Surface()
{
	delete[]pPixels;
	pPixels = nullptr;
}

void Surface::putPixel(int x, int y, Color c)
{
	pPixels[y * width + x] = c;
}

Color Surface::getPixel(int x, int y) const
{
	return pPixels[y * width + x];
}

Surface& Surface::operator=(const Surface& surface)
{
	width = surface.width;
	height = surface.height;

	delete[] pPixels;
	pPixels = new Color[width * height];
	for (int i = 0; i < width * height; i++)
	{
		pPixels[i] = surface.pPixels[i];
	}
	return *this;
}
