#pragma once
#include "SpriteCodex.h"

class MapObject
{
public:
	MapObject(Vec2 startPos, float _width, float _height);
	MapObject() = default;
	~MapObject();

	virtual void moveObject(Vec2 moveVect);
	virtual void drawObject(Graphics& gfx);
	virtual void update();

	Vec2 topLeft;
	float width;
	float height;
};
