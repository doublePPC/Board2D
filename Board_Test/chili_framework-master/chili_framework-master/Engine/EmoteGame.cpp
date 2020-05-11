#include "EmoteGame.h"

EmoteGame::EmoteGame()
	: backgroundAssets(BackgroundContainer()),
    decorAssets(DecorObjectContainer()),
    currentMap(nullptr)
{
    listMaps.emplace_back(EmoteMap(backgroundAssets, decorAssets));
    currentMap = &listMaps[0];
}

EmoteGame::~EmoteGame()
{
}

void EmoteGame::update(float xScroll, float yScroll, float dt)
{
    currentMap->update(xScroll, yScroll, dt);
}

void EmoteGame::drawMap(Graphics& gfx)
{
    currentMap->draw(gfx, backgroundAssets, decorAssets);
}
