#include "EmoteGame.h"

EmoteGame::EmoteGame()
	: backgroundAssets(BackgroundContainer())
{
	BrdData data;
	data.Columns = 16;
	data.Rows = 16;
	for (int i = 0; i < data.Rows * data.Columns; i++)
	{
        currentMap.push_back(map1[i]);
	}
	data.Tile_Height = 100;
	data.Tile_Width = 100;
	data.Grid_DefaultColor = Colors::Gray;
	board = Board(data);
}

EmoteGame::~EmoteGame()
{
}

void EmoteGame::update(float xScroll, float yScroll, float dt)
{
    board.update(xScroll, yScroll, dt);
}

void EmoteGame::draw(Graphics& gfx)
{
	drawBackground(gfx);
	board.draw(gfx);
}

void EmoteGame::drawBackground(Graphics& gfx)
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
            if (currentMap[tileId] == 0)
            {
                gfx.DrawSprite(tileTopLeft, backgroundAssets.getGrass(), visibleArea.topLeft, visibleArea.bottomRight);
            }
            else if (currentMap[tileId] == 1)
            {
                gfx.DrawSprite(tileTopLeft, backgroundAssets.getAsphalt(), visibleArea.topLeft, visibleArea.bottomRight);
            }
            else if (currentMap[tileId] == 2)
            {
                gfx.DrawSprite(tileTopLeft, backgroundAssets.getSidewalk(), visibleArea.topLeft, visibleArea.bottomRight);
            }
        }
    }
}
