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
private:
	int limitWidth;
	int limitHeight;
	float scrollSpeed;
public:
	// public members
	Vec2 bottomRight;
	Vec2 topLeft;
};