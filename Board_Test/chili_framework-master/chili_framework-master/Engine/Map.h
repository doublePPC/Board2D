#pragma once
#include "Colors.h"
#include <fstream>
#include <string>
#include <cassert>
#include "ChiliWin.h"

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
public:
	static constexpr Color grass = RGB(32, 255, 32);
	static constexpr Color asphalt = RGB(42, 42, 42);
	static constexpr Color sidewalk = RGB(145, 145, 145);
};

static const int mapTest[256] =
{
//  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15       
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};