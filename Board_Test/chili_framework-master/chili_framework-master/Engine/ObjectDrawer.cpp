#include "ObjectDrawer.h"

ObjectDrawer::ObjectDrawer(Board& brd)
	: board(brd)
{
}

ObjectDrawer::~ObjectDrawer()
{
}

void ObjectDrawer::addObject(int index, MapObject* object)
{
	assert(index < BrdData::Rows * BrdData::Columns);
	listObjects[index].push_back(object);
}

void ObjectDrawer::addObject(Vec2 pos, MapObject* object)
{
	listObjects[board.pos2Id(pos)].push_back(object);
}

void ObjectDrawer::addObject(int row, int column, MapObject* object)
{
	assert(row < BrdData::Rows);
	assert(column < BrdData::Columns);
	listObjects[row * BrdData::Columns + column].push_back(object);
}
