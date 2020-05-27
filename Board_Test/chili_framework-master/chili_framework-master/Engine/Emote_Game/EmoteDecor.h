#pragma once
#include "EmoteGenericData.h"

class EmoteDecor : public MapObject
{
public:
	EmoteDecor() = delete;
	EmoteDecor(const Vec2& startPos, const Surface& sprite, Pathing path);
	EmoteDecor(const EmoteDecor& ref);
	EmoteDecor& operator= (const EmoteDecor& ref);

private:
	Pathing pathing;
};