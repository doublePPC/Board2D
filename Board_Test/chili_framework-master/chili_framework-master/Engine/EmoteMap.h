#pragma once
#include "EmoteGenericData.h"
#include "EmoteDecor.h"
#include "EmoteHuman.h"

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

class EmoteMap
{
public:
	EmoteMap() = delete;
	EmoteMap(BackgroundContainer& backgrounds, DecorObjectContainer& decors);
	~EmoteMap();
	
	void draw(Graphics& gfx, BackgroundContainer& backgrounds, DecorObjectContainer decors);
	void update(float xScroll, float yScroll, float dt);
	void drawBackground(Graphics& gfx, BackgroundContainer& backgrounds);
	Vec2 getCameraTopLeft();
private:
	Board board;
	std::vector<EmoteDecor> listDecors;
	std::vector<int> backgroundTilesType;
};
