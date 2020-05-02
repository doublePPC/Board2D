#pragma once
#include "BoardGenericData.h"

class Screen
{
public:
	Screen();
	~Screen();

	void update(float xMov, float yMov, float deltaTime);
	void instantMove(Vec2 newTopleft);
	Vec2 convertPos(const Vec2& posToConvert);
	void alignCenter();
	Vec2 getOffsetTopLeft();
private:
	int limitWidth;
	int limitHeight;
	float scrollSpeed;
	Vec2 offset;
public:
	Vec2 bottomRight;
	Vec2 topLeft;
};