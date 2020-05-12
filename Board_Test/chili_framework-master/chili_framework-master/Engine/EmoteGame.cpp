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

void EmoteGame::update(const Keyboard& kbd, const Mouse& mouse, float dt)
{
    float xScroll = 0.0f;
    float yScroll = 0.0f;
    if (kbd.KeyIsPressed(VK_DOWN))
    {
        yScroll = 1.0f;
    }
    if (kbd.KeyIsPressed(VK_UP))
    {
        yScroll = -1.0f;
    }
    if (kbd.KeyIsPressed(VK_LEFT))
    {
        xScroll = -1.0f;
    }
    if (kbd.KeyIsPressed(VK_RIGHT))
    {
        xScroll = 1.0f;
    }
    currentMap->update(xScroll, yScroll, dt);
}

void EmoteGame::drawMap(Graphics& gfx)
{
    currentMap->draw(gfx, backgroundAssets, decorAssets);
}
