#pragma once
#include "EmoteGenericData.h"
#include "EmoteDecor.h"
#include "EmoteHuman.h"

static const mapTile map1[256] =
{
	//  0   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{8,1}, mapTile{0,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{8,1}, mapTile{0,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{8,1}, mapTile{0,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{8,1}, mapTile{0,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{8,1}, mapTile{0,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{8,1}, mapTile{0,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1}, mapTile{1,1},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{8,1}, mapTile{0,2}, mapTile{1,2}, mapTile{1,2}, mapTile{1,2}, mapTile{1,2},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{8,3}, mapTile{7,0}, mapTile{7,0}, mapTile{7,0}, mapTile{7,0}, mapTile{7,0},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,4}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,5}, mapTile{8,4}, mapTile{8,4}, mapTile{8,4}, mapTile{8,4}, mapTile{8,4}, mapTile{8,4}, mapTile{8,4},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1}, mapTile{7,1},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,1}, mapTile{6,2}, mapTile{7,2}, mapTile{7,2}, mapTile{7,2}, mapTile{7,2}, mapTile{7,2}, mapTile{7,2}, mapTile{7,2}, mapTile{7,2}, mapTile{7,2},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{3,2}, mapTile{4,2}, mapTile{4,2}, mapTile{4,2}, mapTile{4,2}, mapTile{4,2}, mapTile{4,2}, mapTile{4,2}, mapTile{4,2}, mapTile{4,2}, mapTile{4,2},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3},
		mapTile{2,3} , mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}, mapTile{2,3}
};

class EmoteMap
{
public:
	EmoteMap() = delete;
	EmoteMap(BackgroundContainer& backgrounds, DecorObjectContainer& decors);
	~EmoteMap();
	
	void draw(Graphics& gfx, DecorObjectContainer decors);
	void update(float xScroll, float yScroll, float dt);
	void drawBackground(Graphics& gfx);
	Vec2 getCameraTopLeft();
private:
	Board board;
	Surface& chipSet;
	std::vector<EmoteDecor> listDecors;
	std::vector<mapTile> backgroundTilesType;
};
