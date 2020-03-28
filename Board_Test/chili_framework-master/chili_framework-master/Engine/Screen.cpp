#include "Screen.h"

Screen::Screen()
{
	// use this constructor for a fixed screen with the size of the window
	topLeft = Vec2(0, 0);
	width = Graphics::ScreenWidth;
	height = Graphics::ScreenHeight;
	limitWidth = Graphics::ScreenWidth;
	limitHeight = Graphics::ScreenHeight;
}

Screen::Screen(int xLimit, int yLimit)
{
	// use this constructor to define the limit of the board with default starting position
	topLeft = Vec2(0, 0);
	width = Graphics::ScreenWidth;
	height = Graphics::ScreenHeight;
	limitWidth = xLimit;
	limitHeight = yLimit;
}

Screen::Screen(int xLimit, int yLimit, Vec2 startPos)
{
	// use this constructor to define the limit of the board and to set a starting position
	topLeft = startPos;
	width = Graphics::ScreenWidth;
	height = Graphics::ScreenHeight;
	limitWidth = xLimit;
	limitHeight = yLimit;
}

Screen::~Screen()
{
}
