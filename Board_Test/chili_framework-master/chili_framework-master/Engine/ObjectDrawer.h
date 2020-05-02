#pragma once
#include "EmoteHuman.h"
#include "Board.h"
#include <assert.h>

class ObjectDrawer
{
public:
	ObjectDrawer(Board& brd);
	~ObjectDrawer();

	void addObject(int index, MapObject* object);
	void addObject(Vec2 pos, MapObject* object);
	void addObject(int row, int column, MapObject* object);
private:
	Board& board;
	std::vector<MapObject*> listObjects[BrdData::Rows * BrdData::Columns];
};