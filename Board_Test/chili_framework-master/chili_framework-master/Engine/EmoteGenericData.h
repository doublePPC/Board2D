#pragma once
#include "Board.h"
#include "MapObject.h"

enum class Pathing
{
	walkable = 0,
	block
};

enum class Facing
{
	down = 0,
	right,
	left,
	up
};

class BackgroundContainer
{
public:
	BackgroundContainer();
	~BackgroundContainer() = default;

	Surface& getGrass();
	Surface& getAsphalt();
	Surface& getSidewalk();
private:
	Surface grass;
	Surface asphalt;
	Surface sidewalk;
};

class DecorObjectContainer
{
public:
	DecorObjectContainer();
	~DecorObjectContainer() = default;

	Surface& getWalkSign();
private:
	Surface walkSign;
};