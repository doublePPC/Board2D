#pragma once
#include "BoardGenericData.h"

class Screen
{
public:
	Screen() = default;
	Screen(const BrdData& brdData);
	Screen(const Screen& refScr);
	Screen& operator= (const Screen& refScr);
	~Screen();

	void update(float xMov, float yMov, float deltaTime);
	void instantMove(Vec2 newTopleft);
	Vec2 convertPos(const Vec2& posToConvert);
	void alignCenter();
	Vec2 getOffsetTopLeft();
private:
	int limitWidth;
	int limitHeight;
	int brdPxWidth;
	int brdPxHeight;
	float scrollSpeed;
	Vec2 offset;
public:
	Vec2 bottomRight;
	Vec2 topLeft;
};