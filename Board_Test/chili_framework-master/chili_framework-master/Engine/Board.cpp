#include "Board.h"

Board::Board()
	:
	camera(Screen(Board::width * BoardTile::tileWidth, Board::height * BoardTile::tileHeight))
{
	for (int i = 0; i < Board::width; i++)
	{
		for (int j = 0; j < Board::height; j++)
		{
			listTiles.push_back(BoardTile(i, j));
		}
	}
}

Board::~Board()
{
	listTiles.clear();
}

Board::BoardTile::BoardTile(int xId, int yId)
	:
	topLeft(Vec2(xId * BoardTile::tileWidth, yId * BoardTile::tileHeight)),
	bottomRight(Vec2(
		xId * BoardTile::tileWidth + BoardTile::tileWidth - 1, 
		yId * BoardTile::tileHeight + BoardTile::tileHeight - 1))
{

}

Board::BoardTile::~BoardTile()
{
}
