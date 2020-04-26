#include "MapObject.h"

MapObject::MapObject(Vec2 startPos, float _width, float _height)
{
	topLeft = startPos;
	width = _width;
	height = _height;
}

MapObject::~MapObject()
{
}

void MapObject::moveObject(Vec2 moveVect)
{
	topLeft += moveVect;
}

void MapObject::drawObject(Graphics& gfx)
{
	
}

void MapObject::update()
{
}
