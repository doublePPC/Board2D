#pragma once
#include "EmoteHuman.h"
#include "EmoteDecor.h"

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
	DecorObjectContainer decorAssets;
	std::vector<int> currentMap;
	std::vector<MapObject*> listStaticObjects;
	Board board;
};