#include "Screen.h"

Screen::Screen()
{
	// use this constructor for a fixed screen with the size of the window
	topLeft = Vec2(0, 0);
	bottomRight = Vec2(Graphics::ScreenWidth -1.0f, Graphics::ScreenHeight -1.0f);
	limitWidth = Graphics::ScreenWidth;
	limitHeight = Graphics::ScreenHeight;
	scrollSpeed = Screen::defaultScrollSpeed;
}

Screen::Screen(int xLimit, int yLimit)
{
	// use this constructor to define the limit of the board with default starting position
	topLeft = Vec2(0, 0);
	bottomRight = Vec2(topLeft.x + Graphics::ScreenWidth -1.0f, topLeft.y + Graphics::ScreenHeight -1.0f);
	limitWidth = xLimit;
	limitHeight = yLimit;
	scrollSpeed = Screen::defaultScrollSpeed;
}

Screen::Screen(int xLimit, int yLimit, Vec2 startPos)
{
	// use this constructor to define the limit of the board and to set a starting position
	topLeft = startPos;
	bottomRight = Vec2(startPos.x + Graphics::ScreenWidth -1.0f, startPos.y + Graphics::ScreenHeight -1.0f);
	limitWidth = xLimit;
	limitHeight = yLimit;
	scrollSpeed = Screen::defaultScrollSpeed;
}

Screen::~Screen()
{
}

void Screen::update(float xMov, float yMov, float deltaTime)
{
	float horiMov = xMov * scrollSpeed * deltaTime;
	float vertMov = yMov * scrollSpeed * deltaTime;
	// horizontal camera movement
	if (bottomRight.x + horiMov >= float(limitWidth))
	{
		// the camera new position would be beyond the right limit
		bottomRight = Vec2(float(limitWidth), bottomRight.y);
		topLeft = Vec2(bottomRight.x - float(Graphics::ScreenWidth), topLeft.y);
	}
	else if (topLeft.x + horiMov < 0.0f)
	{
		// the camera new position would be beyond the left limit
		topLeft = Vec2(0.0f, topLeft.y);
		bottomRight = Vec2(float(Graphics::ScreenWidth - 1), bottomRight.y);
	}
	else
	{
		// the camera new position is between the board boundaries
		topLeft += Vec2(horiMov, 0.0f);
		bottomRight += Vec2(horiMov, 0.0f);
	}
	// vertical camera movement
	if (bottomRight.y + vertMov >= float(limitHeight))
	{
		// the camera new position would be beyond the bottom limit
		bottomRight = Vec2(bottomRight.x, float(limitHeight));
		topLeft = Vec2(topLeft.x, bottomRight.y - float(Graphics::ScreenHeight));
	}
	else if (topLeft.y + vertMov < 0.0f)
	{
		// the camera new position would be beyond the top limit
		topLeft = Vec2(topLeft.x, 0.0f);
		bottomRight = Vec2(bottomRight.x, float(Graphics::ScreenHeight - 1));
	}
	else
	{
		// the camera new position is between vertical boundaries
		topLeft += Vec2(0.0f, vertMov);
		bottomRight += Vec2(0.0f, vertMov);
	}
}

