#pragma once
#include "Board.h"
#include "MapObject.h"

enum class Pathing
{
	walkable = 0,
	block
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

static const int map1[256] =
{
//  0   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0 , 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0 , 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
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