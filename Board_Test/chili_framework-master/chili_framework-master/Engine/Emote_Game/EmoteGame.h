#pragma once
#include "EmoteMap.h"
#include "..\\Windows\\Keyboard.h"
#include "..\\Windows\\Mouse.h"
#include "EmoteInterface.h"
#include "EmoteFileWriter.h"

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
	e_Interface scoreboard;
};