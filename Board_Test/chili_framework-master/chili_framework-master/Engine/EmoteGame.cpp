#include "EmoteGame.h"

EmoteGame::EmoteGame()
	: backgroundAssets(BackgroundContainer()),
    decorAssets(DecorObjectContainer()),
    currentMap(nullptr),
    reiscant1(Surface("Ressources\\ReiscantChar1.bmp"))
{
    listMaps.emplace_back(EmoteMap(backgroundAssets, decorAssets));
    currentMap = &listMaps[0];
    listCharacters.emplace_back(EmoteHuman(Vec2(500.0f, 800.0f), reiscant1, 48, 80));
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
    if (listCharacters.size() > 0)
    {
        if (kbd.KeyIsPressed('M'))
        {
            listCharacters[0].startMoving();
        }
        if (kbd.KeyIsPressed('A'))
        {
            listCharacters[0].accelerate(2);
        }
        if (kbd.KeyIsPressed('D'))
        {
            listCharacters[0].accelerate(-2);
        }
        if (kbd.KeyIsPressed('S'))
        {
            listCharacters[0].stop();
        }
    }
    for (int i = 0; i < listCharacters.size(); i++)
    {
        listCharacters[i].update(dt);
    }
}

void EmoteGame::drawMap(Graphics& gfx)
{
    currentMap->draw(gfx, backgroundAssets, decorAssets);
    for (int i = 0; i < listCharacters.size(); i++)
    {
        listCharacters[i].drawObject(gfx, currentMap->getCameraTopLeft());
    }
}
