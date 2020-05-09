#include "EmoteHuman.h"

EmoteHuman::EmoteHuman(Vec2 startPos, const Surface& sprite)
	: MapObject(startPos, sprite),
	position(startPos)
{
	isSet = true;
}

EmoteHuman::EmoteHuman(const EmoteHuman& ref)
	: MapObject(ref),
	position(ref.position)
{
	isSet = true;
}

EmoteHuman& EmoteHuman::operator=(const EmoteHuman& ref)
{
	model = ref.model;
	topLeft = ref.topLeft;
	position = ref.position;
	isSet = true;
	return *this;
}

EmoteHuman::~EmoteHuman()
{
	model.~Surface();
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
