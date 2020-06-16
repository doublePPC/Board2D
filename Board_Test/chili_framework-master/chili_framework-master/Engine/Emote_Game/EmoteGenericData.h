#pragma once
#include "..\\Board\\Board.h"
#include "..\\Board\\MapObject.h"
#include <fstream>

enum class Pathing
{
	walkable = 0,
	block
};

enum class Facing
{
	down = 0,
	left,
	right,
	up
};

class BackgroundContainer
{
public:
	BackgroundContainer();
	~BackgroundContainer() = default;

	//Surface& getGrass();
	//Surface& getAsphalt();
	//Surface& getSidewalk();
	Surface& getCitySet1();
private:
	//Surface grass;
	//Surface asphalt;
	//Surface sidewalk;
	Surface citySet1;
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

struct mapTile {
	int xId;
	int yId;
};

struct MapDecorData
{
	float topLeftX, topLeftY;
	int decorId;
};

struct MapFileData
{
	static const int intSize = sizeof(int);
	// decomposed Board datas
	int columns, rows, tileWidth, tileHeight;
	unsigned int gridColor;
	// chipset reference
	int chipsetId;
	// decomposed Decors datas 
	std::vector<MapDecorData> listOfDecorsDatas;
	// mapTiles id
	std::vector<mapTile> mapTiles;
};