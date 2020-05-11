#pragma once
#include "EmoteMap.h"

class EmoteGame
{
public:
	EmoteGame();
	~EmoteGame();

	void update(float xScroll, float yScroll, float dt);
	void drawMap(Graphics& gfx);
private:
	BackgroundContainer backgroundAssets;
	DecorObjectContainer decorAssets;
	std::vector<EmoteMap> listMaps;
	EmoteMap* currentMap;
};