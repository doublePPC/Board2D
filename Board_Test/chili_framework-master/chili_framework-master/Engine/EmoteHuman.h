#pragma once
#include "MapObject.h"

class EmoteHuman : public MapObject
{
public:
	EmoteHuman() = default;
	EmoteHuman(Vec2 startPos, Color baseColor);
	~EmoteHuman();

	void moveObject(Vec2 moveVect);
	void drawObject(Graphics& gfx);
	void update();
private:
	Color baseColor;
};