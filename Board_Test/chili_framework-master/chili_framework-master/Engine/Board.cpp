#include "Board.h"

/* ------------------------------
	   Board class section
   ------------------------------ */

// Private Methods
int Board::DrawLign(int lign, Graphics& gfx)
{
	int widthToDraw = Graphics::ScreenWidth;
	int cycleCounter = x2Id(camera.topLeft);
	while (widthToDraw > 0 && cycleCounter < Board::width)
	{
		widthToDraw = widthToDraw - listTiles[cycleCounter][lign].drawTile(camera.topLeft, camera.bottomRight, gfx);
		cycleCounter++;
	}
	// once the lign is drawn, return the amount of pixels it takes vertically on the screen
	if (camera.topLeft.y > lign * BoardTile::tileHeight)
	{
		// the topLeft of the camera is vertically in the lign (so, only a portion of the tile as been drawn)
		return BoardTile::tileHeight - camera.topLeft.y;
	}
	else if (camera.bottomRight.y < lign * BoardTile::tileHeight + (BoardTile::tileHeight - 1))
	{
		// the bottomRight of the camera is above the end of the lign (so, only a portion of the tile as been drawn)
		return camera.bottomRight.y - lign * BoardTile::tileHeight;
	}
	else
	{
		// the topLeft of the camera is above the lign and bottomRight is below (so, the whole vertical size of the tile as been drawn)
		return BoardTile::tileHeight;
	}
}

void Board::DrawMargin(const Vec2& topLeft, const Vec2& bottomRight, Graphics& gfx)
{
	//Vec2 convertedTopLeft = camera.brdCoord2scnCoord(topLeft);
	//Vec2 convertedBottomRight = camera.brdCoord2scnCoord(bottomRight);
	//gfx.DrawRect(convertedTopLeft, convertedBottomRight, Colors::Black);
}


// Constructor and Destructor
Board::Board()
	:
	camera(Screen(Board::width * BoardTile::tileWidth, Board::height * BoardTile::tileHeight)),
	listTiles(Board::width)
{
	for (int i = 0; i < Board::width; i++)
	{
		std::vector<BoardTile> tempVect;
		for (int j = 0; j < Board::height; j++)
		{
			tempVect.push_back(BoardTile(i, j)); 
		}
		listTiles[i] = tempVect;
	}
}

Board::~Board()
{
	listTiles.clear();
}

// Public Methods
int Board::x2Id(const Vec2& point)
{
	// tells in which column the point is
	return int(point.x / BoardTile::tileWidth);
}

int Board::y2Id(const Vec2& point)
{
	// tells in which lign the point is
	return int(point.y / BoardTile::tileHeight);
}

void Board::update(float camXscroll, float camYscroll, float deltaTime)
{
	camera.update(camXscroll, camYscroll, deltaTime);
}

void Board::drawBoard(Graphics& gfx)
{
	// find the first lign of tiles to draw
	int lignToDraw = y2Id(camera.topLeft);
	int heightToDraw = Graphics::ScreenHeight;
	while (heightToDraw > 0 && lignToDraw < Board::height)
	{
		heightToDraw = heightToDraw - DrawLign(lignToDraw, gfx);
		lignToDraw++;
	}
}


/* ------------------------
      Tiles class section
   ------------------------ */

Board::BoardTile::BoardTile(int xId, int yId)
{
	this->xId = xId;
	this->yId = yId;
}

Board::BoardTile::~BoardTile()
{
}

int Board::BoardTile::drawTile(const Vec2& topLeft, const Vec2& bottomRight, Graphics& gfx)
{
	drawPerimeter(topLeft, bottomRight, gfx);
	// once the tile is drawn, return the amount of pixels it takes horizontally on the screen
	if (topLeft.x > xId * BoardTile::tileWidth)
	{
		// the topLeft of the camera is horizontally in the column (so, only a portion of the tile as been drawn)
		return BoardTile::tileWidth - topLeft.x;
	}
	else if (bottomRight.x < xId * BoardTile::tileWidth + (BoardTile::tileWidth - 1))
	{
		// the bottomRight of the camera is to the left the end of the tile (so, only a portion of the tile as been drawn)
		return bottomRight.x - xId * BoardTile::tileWidth;
	}
	else
	{
		// the topLeft of the camera is to the left and bottomRight is to the right (so, the whole horizontal size of the tile as been drawn)
		return BoardTile::tileWidth;
	}
}

void Board::BoardTile::drawPerimeter(const Vec2& topLeft, const Vec2& bottomRight, Graphics& gfx)
{
	// define if starting point is camera's topLeft or tile's topLeft
	Vec2 start = Vec2(xId * BoardTile::tileWidth, yId * BoardTile::tileHeight);
	Vec2 end = Vec2(start.x + (BoardTile::tileWidth - 1), start.y + (BoardTile::tileHeight - 1));
	if (start.x < topLeft.x)
	{
		// the tile's left isn't on the screen
		start = Vec2(topLeft.x, start.y);
	}
	if (start.y < topLeft.y)
	{
		// the tile's top isn't on the screen
		start = Vec2(start.x, topLeft.y);
	}
	if (end.x > bottomRight.x)
	{
		// the tile's right isn't on the screen
		end = Vec2(bottomRight.x, end.y);
	}
	if (end.y > bottomRight.y)
	{
		// the tile's bottom isn't on the screen
		end = Vec2(end.x, bottomRight.y);
	}
	// convert the starting point's board coordinate into the window coordinate
	int convertedX = start.x - topLeft.x;
	int convertedY = start.y - topLeft.y;
	// Left side
	if (topLeft.x <= xId * BoardTile::tileWidth)
	{
		for (int i = 0; i < end.y - start.y; i++)
		{
			if (convertedX < Graphics::ScreenWidth && convertedX >= 0
				&& convertedY + i < Graphics::ScreenHeight && convertedY + i >= 0)
			{
				gfx.PutPixel(convertedX, convertedY + i, Colors::Gray);
			}
		}
	}
	// Top side
	if (topLeft.y <= yId * BoardTile::tileHeight)
	{
		for (int i = 0; i < end.x - start.x; i++)
		{
			if (convertedX + i < Graphics::ScreenWidth && convertedX + i >= 0
				&& convertedY < Graphics::ScreenHeight && convertedY >= 0)
			{
				gfx.PutPixel(convertedX + i, convertedY, Colors::Gray);
			}
			
		}
	}
	// Right side
	if (bottomRight.x >= xId * BoardTile::tileWidth + (BoardTile::tileWidth - 1))
	{
		for (int i = 0; i < end.y - start.y; i++)
		{
			if (convertedX + end.x - start.x < Graphics::ScreenWidth && convertedX + end.x - start.x >= 0
				&& convertedY + i < Graphics::ScreenHeight && convertedY + i >= 0)
			{
				gfx.PutPixel(convertedX + end.x - start.x, convertedY + i, Colors::Gray);
			}
			
		}
	}
	// Bottom side
	if (bottomRight.y >= yId * BoardTile::tileHeight + (BoardTile::tileHeight - 1))
	{
		for (int i = 0; i < end.x - start.x; i++)
		{
			if (convertedX + i < Graphics::ScreenWidth && convertedX + i >= 0
				&& convertedY + end.y - start.y < Graphics::ScreenHeight && convertedY + end.y - start.y >= 0)
			{
				gfx.PutPixel(convertedX + i, convertedY + end.y - start.y, Colors::Gray);
			}
		}
	}
}
