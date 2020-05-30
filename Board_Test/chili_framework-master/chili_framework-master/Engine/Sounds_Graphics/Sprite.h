#pragma once
#include "..\\Generic\\Colors.h"
#include <fstream>
#include <string>
#include <cassert>
#include "..\\Windows\\ChiliWin.h"

class Surface
{
public:
	Surface() = delete;
	Surface(int width, int height);
	Surface(int width, int height, Color c);
	Surface(const Surface& surface);
	Surface(std::string filename);
	~Surface();

	void putPixel(int x, int y, Color c);
	Color getPixel(int x, int y) const;
	std::pair<int, int> getDimension() const;

	Surface& operator=(const Surface& surface);
private:
	int width;
	int height;
	Color* pPixels = nullptr;
};