#include "MapObject.h"

MapObject::MapObject(const Vec2& startPos, const Surface& image)
	: topLeft(startPos),
	model(image)
{
	isSet = true;
	std::pair<int, int> dimension = image.getDimension();
}

MapObject::MapObject(const MapObject& refObj)
	: topLeft(refObj.topLeft),
	model(refObj.model)
{
	isSet = true;
}

MapObject& MapObject::operator=(const MapObject& refObj)
{
	topLeft = refObj.topLeft;
	model = refObj.model;
	isSet = true;
	return *this;
}

MapObject::~MapObject()
{
	model.~Surface();
}

void MapObject::moveObject(Vec2 moveVect)
{
	topLeft += moveVect;
}

void MapObject::drawObject(Graphics& gfx)
{
	assert(isSet);
	std::pair<int, int> dimension = model.getDimension();
	Vec2 bottomRight = Vec2(topLeft.x + float(dimension.first), topLeft.y + float(dimension.second));
	visibilityStatus status = isRectVisible(topLeft, bottomRight);
	if (status != visibilityStatus::off)
	{
		Vec2 visibleTL = visibleTopLeft(topLeft, status);
		Vec2 visibleBR = visibleBottomRight(bottomRight, status);	
		gfx.DrawSprite(topLeft, model, visibleTL, visibleBR, RGB(128, 0, 255), true);
	}
}

void MapObject::drawRevertSprite(Graphics& gfx)
{
}

void MapObject::update()
{
}

Vec2 MapObject::getCenter()
{
	std::pair<int, int> dimension = model.getDimension();
	float x = topLeft.x + float(dimension.first) / 2.0f;
	float y = topLeft.y + float(dimension.second) / 2.0f;
	return Vec2(x, y);
}
