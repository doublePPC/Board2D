#include "ObjectDrawer.h"

ObjectDrawer::ObjectDrawer(Board& brd)
	: board(brd)
{
	if (BrdData::Columns == 16 && BrdData::Rows == 16)
	{
		for (int i = 0; i < 256; i++)
		{
			tilesBackground[i] = mapTest[i];
		}
	}
}

ObjectDrawer::~ObjectDrawer()
{
}

void ObjectDrawer::drawBackground()
{
	std::pair<int, int> rowCol = board.rowColToDraw();
	/*int startId = pos2Id(camera.topLeft);*/
	for (int i = 0; i < rowCol.second; i++)
	{
		for (int j = 0; j < rowCol.first; j++)
		{
			/*int tileId = i * BrdData::Columns + startId + j;
			listTiles[tileId].drawPerimeter(camera.getOffsetTopLeft(), gfx, gridColor);*/
		}
	}
}

//void ObjectDrawer::addObject(int index, MapObject* object)
//{
//	assert(index < BrdData::Rows * BrdData::Columns);
//	listObjects[index].push_back(object);
//}
//
//void ObjectDrawer::addObject(Vec2 pos, MapObject* object)
//{
//	listObjects[board.pos2Id(pos)].push_back(object);
//}
//
//void ObjectDrawer::addObject(int row, int column, MapObject* object)
//{
//	assert(row < BrdData::Rows);
//	assert(column < BrdData::Columns);
//	listObjects[row * BrdData::Columns + column].push_back(object);
//}
