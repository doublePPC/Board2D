#include "Board.h"
#include <assert.h>

// Constructor and Destructor
Board::Board(BrdData initData)
	: camera(Screen(initData)),
	columns(initData.Columns),
	rows(initData.Rows),
	tileWidth(initData.Tile_Width),
	tileHeight(initData.Tile_Height),
	gridColor(initData.Grid_DefaultColor)
{
	gridViewable = BrdData::Grid_DefaultViewable;
	camera.alignCenter();
}

Board::Board(const Board& refBrd)
	: camera(Screen(refBrd.camera)),
	columns(refBrd.columns),
	rows(refBrd.rows),
	tileWidth(refBrd.tileWidth),
	tileHeight(refBrd.tileHeight),
	gridColor(refBrd.gridColor),
	gridViewable(refBrd.gridViewable)
{
	camera.alignCenter();
}

Board& Board::operator=(const Board& refBrd)
{
	camera = refBrd.camera;
	columns = refBrd.columns;
	rows = refBrd.rows;
	tileWidth = refBrd.tileWidth;
	tileHeight = refBrd.tileHeight;
	gridColor = refBrd.gridColor;
	gridViewable = refBrd.gridViewable;
	return *this;
}

Board::~Board()
{
}

// Board Methods
const Vec2& Board::getCamTopLeft()
{
	return camera.topLeft;
}

int Board::pos2Id(const Vec2& point)
{
	int xId = int(point.x) / tileWidth;
	int yId = int(point.y) / tileHeight;
	return int(yId * columns + xId);
}

void Board::update(float camXscroll, float camYscroll, float deltaTime)
{
	camera.update(camXscroll, camYscroll, deltaTime);
}

void Board::draw(Graphics& gfx)
{
	std::pair<int, int> rowCol = rowColToDraw();
	int startId = pos2Id(camera.topLeft);
	for (int i = 0 ; i < rowCol.second ; i++)
	{
		for (int j = 0 ; j < rowCol.first ; j++)
		{
			int tileId = i * columns + startId + j;
			drawPerimeter(tileId, gfx) ;
		}
	}
}

void Board::toggleGridView()
{
	gridViewable = !gridViewable;
}

std::pair<int,int> Board::rowColToDraw()
{
	int amountOfCol = 0;
	int amountOfRow = 0;
	if (Graphics::ScreenWidth >= columns * tileWidth)
	{
		amountOfCol = columns;
	}
	else
	{ 
		if (int(camera.topLeft.x) + Graphics::ScreenWidth >= columns * tileWidth)
		{
			// there is not enough tiles left in the row to fill the screen size
			amountOfCol = ((columns * tileWidth) - int(camera.topLeft.x)) / tileWidth;
			if (((columns * tileWidth) - int(camera.topLeft.x)) % tileWidth > 0)
			{
				amountOfCol++;
			}
		}
		else
		{
			// there is enough tiles left in the row to fill the screen
			amountOfCol = Graphics::ScreenWidth / tileWidth;
			if (getTopLeft(pos2Id(camera.topLeft)).x != camera.topLeft.x)
			{
				amountOfCol++;
			}
		}
	}
	if (Graphics::ScreenHeight >= rows * tileHeight)
	{
		amountOfRow = rows;
	}
	else
	{
		if (int(camera.topLeft.y) + Graphics::ScreenHeight >= rows * tileHeight)
		{
			// there is not enough tiles left in the column to fill the screen size
			amountOfRow = ((rows * tileHeight) - int(camera.topLeft.y)) / tileHeight;
			if (((rows * tileHeight) - int(camera.topLeft.y)) % tileHeight > 0)
			{
				amountOfRow++;
			}
		}
		else
		{
			// there is enough tiles left in the column to fill the screen
			amountOfRow = Graphics::ScreenHeight / tileHeight;
			if (getTopLeft(pos2Id(camera.topLeft)).y != camera.topLeft.y)
			{
				amountOfRow++;
			}
		}
	}
	return std::pair<int,int>(amountOfCol, amountOfRow);
}

Vec2 Board::getTileConvTL(int index)
{
	const float x = float((index % columns) * tileWidth);
	const float y = float((index / columns) * tileHeight);
	return camera.convertPos(Vec2(x, y));
}

// Tiles Methods
TilePortion Board::getVisiblePart(int index)
{
	Vec2 convertedTopLeft = getTopLeft(index) - camera.getOffsetTopLeft();
	Vec2 convertedBottomRight = getBottomRight(index) - camera.getOffsetTopLeft();
	visibilityStatus status = isRectVisible(convertedTopLeft, convertedBottomRight);
	if (status != visibilityStatus::off)
	{
		Vec2 visibleTL = visibleTopLeft(convertedTopLeft, status);
		Vec2 visibleBR = visibleBottomRight(convertedBottomRight, status);
		return TilePortion{ visibleTL, visibleBR };
	}
	else
	{
		return TilePortion{ Vec2(0.0f, 0.0f), Vec2(0.0f, 0.0f) };
	}
}

void Board::drawPerimeter(int index, Graphics& gfx)
{
	if (gridViewable)
	{
		TilePortion visibleArea = getVisiblePart(index);
		if (visibleArea.bottomRight.x - visibleArea.topLeft.x > 0.0f)
		{
			// tile is visible
			if (visibleArea.topLeft.x == getTopLeft(index).x - camera.getOffsetTopLeft().x)
			{
				// drawing Left side
				for (int i = int(visibleArea.topLeft.y); i <= int(visibleArea.bottomRight.y); i++)
				{
					gfx.PutPixel(int(visibleArea.topLeft.x), i, gridColor);
				}
			}
			if (visibleArea.topLeft.y == getTopLeft(index).y - camera.getOffsetTopLeft().y)
			{
				// drawing Top side
				for (int i = int(visibleArea.topLeft.x); i <= int(visibleArea.bottomRight.x); i++)
				{
					gfx.PutPixel(i, int(visibleArea.topLeft.y), gridColor);
				}
			}
			if (visibleArea.bottomRight.x == getBottomRight(index).x - camera.getOffsetTopLeft().x)
			{
				// drawing Right side
				for (int i = int(visibleArea.topLeft.y); i <= int(visibleArea.bottomRight.y); i++)
				{
					gfx.PutPixel(int(visibleArea.bottomRight.x), i, gridColor);
				}
			}
			if (visibleArea.bottomRight.y == getBottomRight(index).y - camera.getOffsetTopLeft().y)
			{
				// drawing Bottom side
				for (int i = int(visibleArea.topLeft.x); i <= int(visibleArea.bottomRight.x); i++)
				{
					gfx.PutPixel(i, int(visibleArea.bottomRight.y), gridColor);
				}
			}
		}
	}
	
}

Vec2 Board::getTopLeft(int index)
{
	float xValue = float((index % columns) * tileWidth);
	float yValue = float((index / columns) * tileHeight);
	return Vec2(xValue, yValue);
}

Vec2 Board::getBottomRight(int index)
{
	float xValue = float((index % columns) * tileWidth + tileWidth - 1);
	float yValue = float((index / columns) * tileHeight + tileHeight - 1);
	return Vec2(xValue, yValue);
}


/* ------------------------
      Tiles class section

TilePortion Board::BoardTile::getVisiblePart(const Vec2& cameraTopLeft)
{
	Vec2 convertedTopLeft = getTopLeft() - cameraTopLeft;
	Vec2 convertedBottomRight = getBottomRight() - cameraTopLeft;
	Vec2 visibleTopLeft = Vec2(0.0f,0.0f), visibleBottomRight = Vec2(0.0f,0.0f);
	// check for topLeft visibility
	if (convertedTopLeft.x >= 0.0f && convertedTopLeft.x < float(Graphics::ScreenWidth))
	{
		// topLeft.x is visible
		if (convertedTopLeft.y >= 0.0f && convertedTopLeft.y < float(Graphics::ScreenHeight))
		{
			// topLeft.y is also visible
			visibleTopLeft = convertedTopLeft;
		}
		else if (convertedBottomRight.y >= 0.0f && convertedBottomRight.y < float(Graphics::ScreenHeight))
		{
			// visible topLeft.y must become top screen since its bottomRight.y is on screen
			visibleTopLeft = Vec2(convertedTopLeft.x, 0.0f);
		}
	}
	else if (convertedBottomRight.x >= 0.0f && convertedBottomRight.x < float(Graphics::ScreenWidth))
	{
		// topLeft.x isn't on screen, but bottomRight.x is
		if (convertedTopLeft.y >= 0.0f && convertedTopLeft.y < float(Graphics::ScreenHeight))
		{
			// topLeft.y is visible though
			visibleTopLeft = Vec2(0.0f, convertedTopLeft.y);
		}		
	}
	// check for bottomRight visibility 
	if (convertedBottomRight.x >= 0.0f && convertedBottomRight.x < float(Graphics::ScreenWidth))
	{
		// bottomRight.x is visible
		if (convertedBottomRight.y >= 0.0f && convertedBottomRight.y < float(Graphics::ScreenHeight))
		{
			// bottomRight.y is also visible
			visibleBottomRight = convertedBottomRight;
		}
		else if (convertedTopLeft.y >= 0.0f && convertedTopLeft.y < float(Graphics::ScreenHeight))
		{
			// visible bottomRight.y must become bottom screen since its topLeft.y is on the screen
			visibleBottomRight = Vec2(convertedBottomRight.x, float(Graphics::ScreenHeight - 1));
		}
	}
	else if (convertedTopLeft.x >= 0.0f && convertedTopLeft.x < float(Graphics::ScreenWidth))
	{
		// bottomRight.x isn't visible, but topLeft.x is
		if (convertedBottomRight.y >= 0.0f && convertedBottomRight.y < float(Graphics::ScreenHeight))
		{
			// bottomRight.y is visible though
			visibleBottomRight = Vec2(float(Graphics::ScreenWidth - 1), convertedBottomRight.y);
		}
		else
		{
			visibleBottomRight = Vec2(float(Graphics::ScreenWidth - 1), float(Graphics::ScreenHeight - 1));
		}
	}
	return TilePortion{ visibleTopLeft, visibleBottomRight };
}

void Board::BoardTile::drawPerimeter(const Vec2& cameraTopLeft, Graphics& gfx, Color gridColor)
{
	TilePortion visibleArea = getVisiblePart(cameraTopLeft);
	if (visibleArea.bottomRight.x - visibleArea.topLeft.x > 0.0f)
	{
		// tile is visible
		if (visibleArea.topLeft.x == getTopLeft().x - cameraTopLeft.x)
		{
			// drawing Left side
			assert(visibleArea.topLeft.y >= 0.0f);
			assert(visibleArea.bottomRight.y < float(Graphics::ScreenHeight));
			for (int i = int(visibleArea.topLeft.y); i <= int(visibleArea.bottomRight.y); i++)
			{
				gfx.PutPixel(int(visibleArea.topLeft.x), i, gridColor);
			}
		}
		if (visibleArea.topLeft.y == getTopLeft().y - cameraTopLeft.y)
		{
			// drawing Top side
			assert(visibleArea.topLeft.x >= 0.0f);
			assert(visibleArea.bottomRight.x < float(Graphics::ScreenWidth));
			for (int i = int(visibleArea.topLeft.x); i <= int(visibleArea.bottomRight.x); i++)
			{
				gfx.PutPixel(i, int(visibleArea.topLeft.y), gridColor);
			}
		}
		if (visibleArea.bottomRight.x == getBottomRight().x - cameraTopLeft.x)
		{
			// drawing Right side
			assert(visibleArea.topLeft.y >= 0.0f);
			assert(visibleArea.bottomRight.y < float(Graphics::ScreenHeight));
			for (int i = int(visibleArea.topLeft.y); i <= int(visibleArea.bottomRight.y); i++)
			{
				gfx.PutPixel(int(visibleArea.bottomRight.x), i, gridColor);
			}
		}
		if (visibleArea.bottomRight.y == getBottomRight().y - cameraTopLeft.y)
		{
			// drawing Bottom side
			assert(visibleArea.topLeft.x >= 0.0f);
			assert(visibleArea.bottomRight.x < float(Graphics::ScreenWidth));
			for (int i = int(visibleArea.topLeft.x); i <= int(visibleArea.bottomRight.x); i++)
			{
				gfx.PutPixel(i, int(visibleArea.bottomRight.y), gridColor);
			}
		}
	}
}
*/

// check for topLeft visibility
//if (convertedTopLeft.x >= 0.0f && convertedTopLeft.x < float(Graphics::ScreenWidth))
//{
//	// topLeft.x is visible
//	if (convertedTopLeft.y >= 0.0f && convertedTopLeft.y < float(Graphics::ScreenHeight))
//	{
//		// topLeft.y is also visible
//		visibleTopLeft = convertedTopLeft;
//	}
//	else if (convertedBottomRight.y >= 0.0f && convertedBottomRight.y < float(Graphics::ScreenHeight))
//	{
//		// visible topLeft.y must become top screen since its bottomRight.y is on screen
//		visibleTopLeft = Vec2(convertedTopLeft.x, 0.0f);
//	}
//}
//else if (convertedBottomRight.x >= 0.0f && convertedBottomRight.x < float(Graphics::ScreenWidth))
//{
//	// topLeft.x isn't on screen, but bottomRight.x is
//	if (convertedTopLeft.y >= 0.0f && convertedTopLeft.y < float(Graphics::ScreenHeight))
//	{
//		// topLeft.y is visible though
//		visibleTopLeft = Vec2(0.0f, convertedTopLeft.y);
//	}
//}
//// check for bottomRight visibility 
//if (convertedBottomRight.x >= 0.0f && convertedBottomRight.x < float(Graphics::ScreenWidth))
//{
//	// bottomRight.x is visible
//	if (convertedBottomRight.y >= 0.0f && convertedBottomRight.y < float(Graphics::ScreenHeight))
//	{
//		// bottomRight.y is also visible
//		visibleBottomRight = convertedBottomRight;
//	}
//	else if (convertedTopLeft.y >= 0.0f && convertedTopLeft.y < float(Graphics::ScreenHeight))
//	{
//		// visible bottomRight.y must become bottom screen since its topLeft.y is on the screen
//		visibleBottomRight = Vec2(convertedBottomRight.x, float(Graphics::ScreenHeight - 1));
//	}
//}
//else if (convertedTopLeft.x >= 0.0f && convertedTopLeft.x < float(Graphics::ScreenWidth))
//{
//	// bottomRight.x isn't visible, but topLeft.x is
//	if (convertedBottomRight.y >= 0.0f && convertedBottomRight.y < float(Graphics::ScreenHeight))
//	{
//		// bottomRight.y is visible though
//		visibleBottomRight = Vec2(float(Graphics::ScreenWidth - 1), convertedBottomRight.y);
//	}
//	else
//	{
//		visibleBottomRight = Vec2(float(Graphics::ScreenWidth - 1), float(Graphics::ScreenHeight - 1));
//	}
//}
