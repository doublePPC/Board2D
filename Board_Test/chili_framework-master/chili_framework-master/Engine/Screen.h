#pragma once
#include "EmoteHuman.h"

class Screen
{
public:
	Screen();
	Screen(int xLimit, int yLimit);
	Screen(int xLimit, int yLimit, Vec2 startPos);
	~Screen();

	void update(float xMov, float yMov, float deltaTime);
private:
	int limitWidth;
	int limitHeight;
	float scrollSpeed;
public:
	// public members
	Vec2 bottomRight;
	Vec2 topLeft;
	static constexpr float defaultScrollSpeed = 120.0f;
};