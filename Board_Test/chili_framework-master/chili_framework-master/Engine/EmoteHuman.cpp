#include "EmoteHuman.h"

EmoteHuman::EmoteHuman(Vec2 startPos, const Surface& sprite, int width, int height)
	: MapObject(startPos, sprite),
	velocity(Vec2(0.0f, 0.0f)),
	facing(Facing::down),
	width(width),
	height(height),
	speed(0),
	moveProgression(0.0f),
	animation(Animation(4, 0.25f, animationData{ width, height, 4, 0, EmoteHuman::transparentColor }))
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
	moveProgression(ref.moveProgression),
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
	moveProgression = ref.moveProgression;
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

void EmoteHuman::moveObject(float dt)
{
	moveProgression += float(speed) * dt;
	if (moveProgression >= 1.0f)
	{
		topLeft.x += 1.0f * velocity.x;
		topLeft.y += 1.0f * velocity.y;
		moveProgression -= 1.0f;
	}	
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
	if (velocity.x != 0.0f || velocity.y != 0.0f)
	{
		checkFacing();
		moveObject(dt);
		animation.update(speed, facing, dt);
	}
}

void EmoteHuman::startMoving()
{
	velocity = Vec2(1.0f, 0.0f);
	speed = 40;
}

void EmoteHuman::accelerate(int value)
{
	if (speed != 0)
	{
		if (speed + value < 0)
		{
			speed = 0;
			velocity = Vec2(0.0f, 0.0f);
		}
		else
		{
			speed += value;
			bool check = true;
		}
	}
}

void EmoteHuman::stop()
{
	speed = 0;
	velocity = Vec2(0.0f, 0.0f);
}
