#include "Board.h"
#include <assert.h>

/* ------------------------------
	   Board class section
   ------------------------------ */

// Private Methods

void Board::DrawMargin(const Vec2& topLeft, const Vec2& bottomRight, Graphics& gfx)
{
	//Vec2 convertedTopLeft = camera.brdCoord2scnCoord(topLeft);
	//Vec2 convertedBottomRight = camera.brdCoord2scnCoord(bottomRight);
	//gfx.DrawRect(convertedTopLeft, convertedBottomRight, Colors::Black);
}


// Constructor and Destructor
Board::Board()
	:
	camera(Screen(BrdData::Columns * BrdData::Tile_Width -1, BrdData::Rows * BrdData::Tile_Height -1))
{
	for (int i = 0; i < BrdData::Columns * BrdData::Rows; i++)
	{
		listTiles.push_back(BoardTile(i));
	}
	gridColor = Colors::Gray;
	gridViewable = BrdData::Grid_DefaultViewable;
}

Board::~Board()
{
	listTiles.clear();
}

// Public Methods
int Board::pos2Id(const Vec2& point)
{
	int xId = int(point.x) / BrdData::Tile_Width;
	int yId = int(point.y) / BrdData::Tile_Height;
	return int(yId * BrdData::Columns + xId);
}

void Board::update(float camXscroll, float camYscroll, float deltaTime)
{
	camera.update(camXscroll, camYscroll, deltaTime);
}

void Board::draw(Graphics& gfx)
{
	std::pair<int, int> rowCol = rowColToDrawFromTopLeft();
	int startId = pos2Id(camera.topLeft);
	for (int i = 0 ; i < rowCol.second ; i++)
	{
		for (int j = 0 ; j < rowCol.first ; j++)
		{
			int tileId = i * BrdData::Columns + startId + j;
			listTiles[tileId].drawPerimeter(camera.topLeft, gfx, gridColor) ;
		}
	}
}

void Board::toggleGridView()
{
	gridViewable = !gridViewable;
}

std::pair<int,int> Board::rowColToDrawFromTopLeft()
{
	int amountOfCol = 0;
	int amountOfRow = 0;
	if (Graphics::ScreenWidth >= BrdData::Columns * BrdData::Tile_Width)
	{
		amountOfCol = BrdData::Columns;
	}
	else
	{ 
		if (int(camera.topLeft.x) + Graphics::ScreenWidth >= BrdData::Columns * BrdData::Tile_Width)
		{
			// there is not enough tiles left in the row to fill the screen size
			amountOfCol = ((BrdData::Columns * BrdData::Tile_Width) - int(camera.topLeft.x)) / BrdData::Tile_Width;
			if (((BrdData::Columns * BrdData::Tile_Width) - int(camera.topLeft.x)) % BrdData::Tile_Width > 0)
			{
				amountOfCol++;
			}
		}
		else
		{
			// there is enough tiles left in the row to fill the screen
			amountOfCol = Graphics::ScreenWidth / BrdData::Tile_Width;
			if (listTiles[pos2Id(camera.topLeft)].getTopLeft().x != camera.topLeft.x)
			{
				amountOfCol++;
			}
		}
	}
	if (Graphics::ScreenHeight >= BrdData::Rows * BrdData::Tile_Height)
	{
		amountOfRow = BrdData::Rows;
	}
	else
	{
		if (int(camera.topLeft.y) + Graphics::ScreenHeight >= BrdData::Rows * BrdData::Tile_Height)
		{
			// there is not enough tiles left in the column to fill the screen size
			amountOfRow = ((BrdData::Rows * BrdData::Tile_Height) - int(camera.topLeft.y)) / BrdData::Tile_Height;
			if (((BrdData::Rows * BrdData::Tile_Height) - int(camera.topLeft.y)) % BrdData::Tile_Height > 0)
			{
				amountOfRow++;
			}
		}
		else
		{
			// there is enough tiles left in the column to fill the screen
			amountOfRow = Graphics::ScreenHeight / BrdData::Tile_Height;
			if (listTiles[pos2Id(camera.topLeft)].getTopLeft().y != camera.topLeft.y)
			{
				amountOfRow++;
			}
		}
	}
	
	return std::pair<int,int>(amountOfCol, amountOfRow);
}

/* ------------------------
      Tiles class section
   ------------------------ */

Board::BoardTile::BoardTile(int Id)
{
	id = Id;
}

Board::BoardTile::~BoardTile()
{
}

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

Vec2 Board::BoardTile::getTopLeft()
{
	float xValue = float((id % BrdData::Columns) * BrdData::Tile_Width);
	float yValue = float((id / BrdData::Columns) * BrdData::Tile_Height);
	return Vec2(xValue, yValue);
}

Vec2 Board::BoardTile::getBottomRight()
{
	float xValue = float((id % BrdData::Columns) * BrdData::Tile_Width + BrdData::Tile_Width -1);
	float yValue = float((id / BrdData::Columns) * BrdData::Tile_Height + BrdData::Tile_Height -1);
	return Vec2(xValue, yValue);
}
