#pragma once
#include "BoardGenericData.h"

class MapObject
{
public:
	MapObject(const Vec2& startPos, const Surface& image);
	MapObject(const MapObject& refObj);
	MapObject& operator= (const MapObject& refObj);
	MapObject() = default;
	~MapObject();

	virtual void moveObject(Vec2 moveVect);
	virtual void drawObject(Graphics& gfx);
	virtual void update();

	Vec2 topLeft;
	Surface model;
private:
	bool isSet = false;
};
