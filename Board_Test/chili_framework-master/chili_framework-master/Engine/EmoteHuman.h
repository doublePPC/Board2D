#pragma once
#include "EmoteGenericData.h"

class EmoteHuman : public MapObject
{
public:
	EmoteHuman() = delete;
	EmoteHuman(Vec2 startPos, const Surface& sprite);
	EmoteHuman(const EmoteHuman& ref);
	EmoteHuman& operator= (const EmoteHuman& ref);
	~EmoteHuman();

	void checkFacing();
	void moveObject(Vec2 moveVect);
	void drawObject(Graphics& gfx);
	void update();
private:
	bool isSet = false;
	Vec2 velocity;
	Facing facing;
public:
	static constexpr Color transparentColor = RGB(128, 0, 255);
};