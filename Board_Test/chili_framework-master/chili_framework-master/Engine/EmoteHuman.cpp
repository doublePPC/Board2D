#include "EmoteHuman.h"

EmoteHuman::EmoteHuman(Vec2 startPos, const Surface& sprite)
	: MapObject(startPos, sprite)
{
	isSet = true;
	velocity = Vec2(0.0f, 0.0f);
	facing = Facing::down;
}

EmoteHuman::EmoteHuman(const EmoteHuman& ref)
	: MapObject(ref),
	velocity(ref.velocity),
	facing(ref.facing)
{
	isSet = true;
}

EmoteHuman& EmoteHuman::operator=(const EmoteHuman& ref)
{
	model = ref.model;
	topLeft = ref.topLeft;
	velocity = ref.velocity;
	facing = ref.facing;
	isSet = true;
	return *this;
}

EmoteHuman::~EmoteHuman()
{
}

void EmoteHuman::checkFacing()
{
	if (velocity.x > 0.0f)
	{
		facing = Facing::right;
	}
	else if (velocity.x < 0.0f)
	{
		facing = Facing::left;
	}
	else if (velocity.y > 0.0f)
	{
		facing = Facing::down;
	}
	else if (velocity.y < 0.0f)
	{
		facing = Facing::up;
	}
}

void EmoteHuman::moveObject(Vec2 moveVect)
{
	topLeft.x += moveVect.x;
	topLeft.y += moveVect.y;
}

void EmoteHuman::drawObject(Graphics& gfx)
{
	
}

void EmoteHuman::update()
{
	if (velocity.x != 0.0f && velocity.y != 0.0f)
	{
		checkFacing();
		moveObject(velocity);
	}
}
