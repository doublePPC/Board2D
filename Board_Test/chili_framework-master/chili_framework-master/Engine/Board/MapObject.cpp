#include "MapObject.h"

MapObject::MapObject(const Vec2& startPos, const Surface& image)
	: topLeft(startPos),
	model(image)
{
	isSet = true;
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

void MapObject::drawObject(Graphics& gfx, const Vec2& convertionVector)
{
	assert(isSet);
	std::pair<int, int> dimension = model.getDimension();
	TilePortion visiblePart = getVisiblePart(convertionVector, dimension.first, dimension.second);
	if (visiblePart.topLeft != visiblePart.bottomRight)
	{	
		gfx.DrawSprite(topLeft - convertionVector, model, visiblePart.topLeft, visiblePart.bottomRight, RGB(128, 0, 255), true);
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

TilePortion MapObject::getVisiblePart(const Vec2& convertionVector, int width, int height)
{
	Vec2 convertedBottomRight = Vec2(topLeft.x + float(width), topLeft.y + float(height)) - convertionVector;
	Vec2 convertedTopLeft = topLeft - convertionVector;
	visibilityStatus status = isRectVisible(convertedTopLeft, convertedBottomRight);
	if (status == visibilityStatus::off)
	{
		return TilePortion{ Vec2(0.0f, 0.0f), Vec2(0.0f, 0.0f) };
	}
	else
	{
		Vec2 visibleTL = visibleTopLeft(convertedTopLeft, status);
		Vec2 visibleBR = visibleBottomRight(convertedBottomRight, status);
		return TilePortion{ visibleTL, visibleBR };
	}
}
