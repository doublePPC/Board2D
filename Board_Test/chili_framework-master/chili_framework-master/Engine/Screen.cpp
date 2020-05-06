#include "Screen.h"

Screen::Screen(const BrdData& brdData)
{
	brdPxWidth = brdData.Columns * brdData.Tile_Width;
	brdPxHeight = brdData.Rows * brdData.Tile_Height;
	if (Graphics::ScreenWidth >= brdPxWidth)
	{
		limitWidth = BrdData::Cam_X_Size;
	}
	else
	{
		limitWidth = brdPxWidth -1;
	}
	if (Graphics::ScreenHeight >= brdPxHeight)
	{
		limitHeight = BrdData::Cam_Y_Size;
	}
	else
	{
		limitHeight = brdPxHeight -1;
	}
	topLeft = Vec2(0.0f, 0.0f);
	bottomRight = Vec2(BrdData::Cam_X_Size - 1.0f, BrdData::Cam_Y_Size - 1.0f);
	offset = Vec2(0.0f, 0.0f);
	scrollSpeed = float(BrdData::Cam_Speed);
}

Screen::Screen(const Screen& refScr)
	: brdPxWidth(refScr.brdPxWidth),
	  brdPxHeight(refScr.brdPxHeight),
	  limitWidth(refScr.limitWidth),
	  limitHeight(refScr.limitHeight),
	  topLeft(refScr.topLeft),
	  bottomRight(refScr.bottomRight),
	  offset(refScr.offset),
	  scrollSpeed(refScr.scrollSpeed)
{
}

Screen& Screen::operator=(const Screen& refScr)
{
	brdPxWidth = refScr.brdPxWidth;
	brdPxHeight = refScr.brdPxHeight;
	limitWidth = refScr.limitWidth;
	limitHeight = refScr.limitHeight;
	topLeft = refScr.topLeft;
	bottomRight = refScr.bottomRight;
	offset = refScr.offset;
	scrollSpeed = refScr.scrollSpeed;
	return *this;
}

Screen::~Screen()
{
}

void Screen::update(float xMov, float yMov, float deltaTime)
{
	if (limitWidth > Graphics::ScreenWidth && limitHeight > Graphics::ScreenHeight)
	{
		int horiMov = int(xMov * scrollSpeed * deltaTime);
		int vertMov = int(yMov * scrollSpeed * deltaTime);
		// horizontal camera movement
		if (int(bottomRight.x) + horiMov >= limitWidth)
		{
			// the camera new position would be beyond the right limit
			bottomRight = Vec2(float(limitWidth), bottomRight.y);
			topLeft = Vec2(bottomRight.x - float(Graphics::ScreenWidth - 1), topLeft.y);
		}
		else if (int(topLeft.x) + horiMov < 0)
		{
			// the camera new position would be beyond the left limit
			topLeft = Vec2(0.0f, topLeft.y);
			bottomRight = Vec2(float(Graphics::ScreenWidth - 1), bottomRight.y);
		}
		else
		{
			// the camera new position is between the board boundaries
			topLeft += Vec2(float(horiMov), 0.0f);
			bottomRight += Vec2(float(horiMov), 0.0f);
		}
		// vertical camera movement
		if (int(bottomRight.y) + vertMov >= limitHeight)
		{
			// the camera new position would be beyond the bottom limit
			bottomRight = Vec2(bottomRight.x, float(limitHeight));
			topLeft = Vec2(topLeft.x, bottomRight.y - float(Graphics::ScreenHeight - 1));
		}
		else if (int(topLeft.y) + vertMov < 0)
		{
			// the camera new position would be beyond the top limit
			topLeft = Vec2(topLeft.x, 0.0f);
			bottomRight = Vec2(bottomRight.x, float(Graphics::ScreenHeight - 1));
		}
		else
		{
			// the camera new position is between vertical boundaries
			topLeft += Vec2(0.0f, float(vertMov));
			bottomRight += Vec2(0.0f, float(vertMov));
		}
	}
}

void Screen::instantMove(Vec2 newTopleft)
{

}

Vec2 Screen::convertPos(const Vec2& posToConvert)
{
	// returns a vector with screen coordinates instead of board coordinates
	return Vec2(posToConvert.x - topLeft.x, posToConvert.y - topLeft.y);
}

void Screen::alignCenter()
{
	int x = 0, y = 0;
	if (brdPxWidth < Graphics::ScreenWidth)
	{
		if ((Graphics::ScreenWidth - brdPxWidth) / 2 >= 1)
		{
			x = (Graphics::ScreenWidth - brdPxWidth) / 2;
		}
	}
	if (brdPxHeight < Graphics::ScreenHeight)
	{
		if ((Graphics::ScreenHeight - brdPxHeight) / 2 >= 1)
		{
			y = (Graphics::ScreenHeight - brdPxHeight) / 2;
		}
	}
	offset = Vec2(float(x), float(y));
}

Vec2 Screen::getOffsetTopLeft()
{
	return Vec2(topLeft.x - offset.x, topLeft.y - offset.y);
}

