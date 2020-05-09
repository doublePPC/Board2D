#pragma once
#include "EmoteHuman.h"

class EmoteGame
{
public:
	EmoteGame();
	~EmoteGame();

	void update(float xScroll, float yScroll, float dt);
	void draw(Graphics& gfx);
	void drawBackground(Graphics& gfx);
private:
	BackgroundContainer backgroundAssets;
	std::vector<int> currentMap;
	Board board;
};