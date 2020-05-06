#include "EmoteGame.h"

EmoteGame::EmoteGame()
{
	BrdData data;
	data.Columns = 16;
	data.Rows = 16;
	data.Tile_Height = 100;
	data.Tile_Width = 100;
	data.Grid_DefaultColor = Colors::Gray;
	board = Board(data);
}

EmoteGame::~EmoteGame()
{
}

void EmoteGame::update(float dt)
{
}

void EmoteGame::draw(Graphics& gfx)
{
}
