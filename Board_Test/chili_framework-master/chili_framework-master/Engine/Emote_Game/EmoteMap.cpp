#include "EmoteMap.h"

EmoteMap::EmoteMap(BackgroundContainer& backgrounds, DecorObjectContainer& decors)
	: chipSet(backgrounds.getCitySet1())
{
	BrdData data;
	data.Columns = 16;
	data.Rows = 16;
	backgroundTilesType.reserve(256);
	for (int i = 0; i < data.Rows * data.Columns; i++)
	{
		backgroundTilesType.push_back(map1[i]);
	}
	data.Tile_Height = 100;
	data.Tile_Width = 100;
	data.Grid_DefaultColor = Colors::Gray;
	board = Board(data);
	listDecors.emplace_back(EmoteDecor(Vec2(1100.0f, 20.0f), decors.getWalkSign(), Pathing::block));
}

EmoteMap::~EmoteMap()
{
	listDecors.clear();
}

void EmoteMap::draw(Graphics& gfx, DecorObjectContainer decors)
{
	drawBackground(gfx);
	board.draw(gfx);
	if (listDecors.size() > 0)
	{
		for (int i = 0; i < listDecors.size(); i++)
		{
			listDecors[i].drawObject(gfx, board.getCamTopLeft());
		}
	}
}

void EmoteMap::update(float xScroll, float yScroll, float dt)
{
	board.update(xScroll, yScroll, dt);
}

void EmoteMap::drawBackground(Graphics& gfx)
{
	std::pair<int, int> rowCol = board.rowColToDraw();
	int startId = board.pos2Id(board.getCamTopLeft());
	for (int i = 0; i < rowCol.second; i++)
	{
		for (int j = 0; j < rowCol.first; j++)
		{
			int tileId = i * 16 + startId + j;
			TilePortion visibleArea = board.getVisiblePart(tileId);
			Vec2 tileTopLeft = board.getTileConvTL(tileId);
			int startX = backgroundTilesType[tileId].xId * 100;
			int startY = backgroundTilesType[tileId].yId * 100;
			gfx.DrawSheetFragment(tileTopLeft, chipSet, visibleArea.topLeft, visibleArea.bottomRight, Colors::Magenta, startX, startY);
		}
	}
}

Vec2 EmoteMap::getCameraTopLeft()
{
	return board.getCamTopLeft();
}

Board EmoteMap::getBoard()
{
	return board;
}
