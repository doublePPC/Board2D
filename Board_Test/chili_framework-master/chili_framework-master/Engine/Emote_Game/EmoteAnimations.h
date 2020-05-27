#pragma once
#include "EmoteGenericData.h"

struct animationData
{
	int sheetUnitWidth;
	int sheetUnitHeight;
	int currentAnimX; // the X value is the actual animation (0 being standstill and 1 to 4 being walk)
	int currentAnimY; // the Y value in the sheet equals the facing
	Color transparentColor;
};

class Animation
{
private:
	void adjustFacing(const Facing currentFacing);
	void adjustAnimation(float dt);
public:
	Animation() = delete;
	Animation(int amountOfAnim, float animationDelay, const animationData& animDat);
	Animation(const Animation& ref);
	Animation& operator=(const Animation& ref);
	~Animation();

	void update(int speed, const Facing currentFacing, float dt);
	void draw(Surface& refSprite, Graphics& gfx, const Vec2& convertedPos, TilePortion visiblePart);
private:
	float animationDelay;
	float animTimeElapsed;
	int amountOfAnim;
	animationData animData;
};