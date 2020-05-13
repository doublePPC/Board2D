#include "EmoteHuman.h"

EmoteHuman::EmoteHuman(Vec2 startPos, const Surface& sprite, int width, int height)
	: MapObject(startPos, sprite),
	velocity(Vec2(0.0f, 0.0f)),
	facing(Facing::down),
	width(width),
	height(height),
	speed(0),
	animation(Animation(4, 0.25f, animationData{ width, height, 0, 0, EmoteHuman::transparentColor }))
{
	isSet = true;	
}

EmoteHuman::EmoteHuman(const EmoteHuman& ref)
	: MapObject(ref),
	velocity(ref.velocity),
	facing(ref.facing),
	width(ref.width),
	height(ref.height),
	speed(ref.speed),
	animation(ref.animation)
{
	isSet = true;
}

EmoteHuman& EmoteHuman::operator=(const EmoteHuman& ref)
{
	model = ref.model;
	topLeft = ref.topLeft;
	velocity = ref.velocity;
	facing = ref.facing;
	width = ref.width;
	height = ref.height;
	speed = ref.speed;
	animation = ref.animation;
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

void EmoteHuman::drawObject(Graphics& gfx, const Vec2& convertionVector)
{
	Vec2 convertedTopLeft = topLeft - convertionVector;
	TilePortion visiblePart = getVisiblePart(convertionVector, width, height);
	if (visiblePart.topLeft != visiblePart.bottomRight)
	{
		animation.draw(model, gfx, convertedTopLeft, visiblePart);
	}
}

void EmoteHuman::update(float dt)
{
	if (velocity.x != 0.0f && velocity.y != 0.0f)
	{
		checkFacing();
		moveObject(velocity);
		animation.update(speed, facing, dt);
	}
}
