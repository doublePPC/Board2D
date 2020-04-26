#include "EmoteHuman.h"

EmoteHuman::EmoteHuman(Vec2 startPos, Color baseColor)
	: MapObject(startPos, 42.0f, 42.0f),
	baseColor(baseColor)
{
}

EmoteHuman::~EmoteHuman()
{
}

void EmoteHuman::moveObject(Vec2 moveVect)
{
}

void EmoteHuman::drawObject(Graphics& gfx)
{
	SpriteCodex::DrawCircle(topLeft, gfx, baseColor);
}

void EmoteHuman::update()
{
}
