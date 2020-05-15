#pragma once
#include "EmoteMap.h"
#include "Keyboard.h"
#include "Mouse.h"

class EmoteGame
{
public:
	EmoteGame();
	~EmoteGame();

	void update(Keyboard& kbd, const Mouse& mouse, float dt);
	void drawMap(Graphics& gfx);
private:
	BackgroundContainer backgroundAssets;
	DecorObjectContainer decorAssets;
	std::vector<EmoteMap> listMaps;
	EmoteMap* currentMap;
	Surface reiscant1;
	std::vector<EmoteHuman> listCharacters;
};