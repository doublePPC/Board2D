#pragma once
#include "EmoteGenericData.h"
#include "EmoteAnimations.h"

class EmoteHuman : public MapObject
{
public:
	EmoteHuman() = delete;
	EmoteHuman(Vec2 startPos, const Surface& sprite, int width, int height);
	EmoteHuman(const EmoteHuman& ref);
	EmoteHuman& operator= (const EmoteHuman& ref);
	~EmoteHuman();

	void checkFacing();
	void moveObject(float dt);
	void drawObject(Graphics& gfx, const Vec2& convertionVector);
	void update(float dt);
	void startMoving();
	void accelerate(int value);
	void stop();
private:
	bool isSet = false;
	Vec2 velocity;
	Facing facing;
	int width;
	int height;
	int speed;
	float moveProgression;
	Animation animation;
public:
	static constexpr Color transparentColor = RGB(128, 0, 255);
};