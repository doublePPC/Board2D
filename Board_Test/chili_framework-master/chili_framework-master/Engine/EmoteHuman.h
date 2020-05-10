#pragma once
#include "EmoteGenericData.h"

class EmoteHuman : public MapObject
{
public:
	EmoteHuman() = default;
	EmoteHuman(Vec2 startPos, const Surface& sprite);
	EmoteHuman(const EmoteHuman& ref);
	EmoteHuman& operator= (const EmoteHuman& ref);
	~EmoteHuman();

	void moveObject(Vec2 moveVect);
	void drawObject(Graphics& gfx);
	void update();
private:
	bool isSet = false;
};