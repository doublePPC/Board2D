#pragma once
#include "Graphics.h"

class Screen
{
public:
	Screen();
	Screen(int xLimit, int yLimit);
	Screen(int xLimit, int yLimit, Vec2 startPos);
	~Screen();
private:
	int width;
	int height;
	Vec2 topLeft;
	int limitWidth;
	int limitHeight;
};