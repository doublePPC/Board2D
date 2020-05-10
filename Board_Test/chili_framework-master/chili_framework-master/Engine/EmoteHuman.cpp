#include "EmoteHuman.h"

EmoteHuman::EmoteHuman(Vec2 startPos, const Surface& sprite)
	: MapObject(startPos, sprite)
{
	isSet = true;
}

EmoteHuman::EmoteHuman(const EmoteHuman& ref)
	: MapObject(ref)
{
	isSet = true;
}

EmoteHuman& EmoteHuman::operator=(const EmoteHuman& ref)
{
	model = ref.model;
	topLeft = ref.topLeft;
	isSet = true;
	return *this;
}

EmoteHuman::~EmoteHuman()
{
}

void EmoteHuman::moveObject(Vec2 moveVect)
{
}

void EmoteHuman::drawObject(Graphics& gfx)
{
	
}

void EmoteHuman::update()
{
}
