#include "EmoteGame.h"

EmoteGame::EmoteGame()
	: backgroundAssets(BackgroundContainer()),
    decorAssets(DecorObjectContainer()),
    currentMap(nullptr),
    reiscant1(Surface("Ressources\\Emote_Ress\\ReiscantChar1.bmp")),
    scoreboard(e_Interface(Colors::Blue, Vec2(700.0f, 0.0f), Vec2(799.0f, 599.0f)))
{
    listMaps.emplace_back(EmoteMap(backgroundAssets, decorAssets));
    currentMap = &listMaps[0];
    listCharacters.emplace_back(EmoteHuman(Vec2(500.0f, 800.0f), reiscant1, 48, 80));
}

EmoteGame::~EmoteGame()
{
}

void EmoteGame::update(Keyboard& kbd, const Mouse& mouse, float dt)
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
        if (kbd.OneTimeKeyPress('M'))
        {
            listCharacters[0].startMoving(0.0f, 1.0f);
        }
        if (kbd.OneTimeKeyPress('K'))
        {
            listCharacters[0].startMoving(1.0f, 0.0f);
        }
        if (kbd.OneTimeKeyPress('J'))
        {
            listCharacters[0].startMoving(-1.0f, 0.0f);
        }
        if (kbd.OneTimeKeyPress('I'))
        {
            listCharacters[0].startMoving(0.0f, -1.0f);
        }
        if (kbd.OneTimeKeyPress('A'))
        {
            listCharacters[0].accelerate(5);
        }
        if (kbd.OneTimeKeyPress('D'))
        {
            listCharacters[0].accelerate(-5);
        }
        if (kbd.OneTimeKeyPress('S'))
        {
            listCharacters[0].stop();
        }
    }
    if (kbd.OneTimeKeyPress('F'))
    {
        EmoteFileWriter::createMapFile("test", MapFileData{});
    }
    if (kbd.OneTimeKeyPress('G'))
    {
        EmoteFileReader::readMapFile("test");
    }
    if (kbd.OneTimeKeyPress('T'))
    {
        unsigned char* data = listMaps[0].getBoard().save();
        Board newBoard = Board::load(data);
        delete data;
    }
    for (int i = 0; i < listCharacters.size(); i++)
    {
        listCharacters[i].update(dt);
    }
}

void EmoteGame::drawMap(Graphics& gfx)
{
    currentMap->draw(gfx, decorAssets);
    for (int i = 0; i < listCharacters.size(); i++)
    {
        listCharacters[i].drawObject(gfx, currentMap->getCameraTopLeft());
    }
    scoreboard.draw(gfx);
}
