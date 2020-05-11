#include "EmoteMap.h"

EmoteMap::EmoteMap(BackgroundContainer& backgrounds, DecorObjectContainer& decors)
{
	BrdData data;
	data.Columns = 16;
	data.Rows = 16;
	backgroundTilesType.reserve(data.Columns * data.Rows);
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

void EmoteMap::draw(Graphics& gfx, BackgroundContainer& backgrounds, DecorObjectContainer decors)
{
	drawBackground(gfx, backgrounds);
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

void EmoteMap::drawBackground(Graphics& gfx, BackgroundContainer& backgrounds)
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
			//gfx.DrawRect(visibleArea.topLeft, visibleArea.bottomRight, map[tileId]);
			if (backgroundTilesType[tileId] == 0)
			{
				gfx.DrawSprite(tileTopLeft, backgrounds.getGrass(), visibleArea.topLeft, visibleArea.bottomRight, RGB(255, 0, 128), false);
			}
			else if (backgroundTilesType[tileId] == 1)
			{
				gfx.DrawSprite(tileTopLeft, backgrounds.getAsphalt(), visibleArea.topLeft, visibleArea.bottomRight, RGB(255, 0, 128), false);
			}
			else if (backgroundTilesType[tileId] == 2)
			{
				gfx.DrawSprite(tileTopLeft, backgrounds.getSidewalk(), visibleArea.topLeft, visibleArea.bottomRight, RGB(255, 0, 128), false);
			}
		}
	}
}
