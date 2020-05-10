#include "EmoteDecor.h"

EmoteDecor::EmoteDecor(const Vec2& startPos, const Surface& sprite, Pathing path)
	: MapObject(startPos, sprite),
	pathing(path)
{
}

EmoteDecor::EmoteDecor(const EmoteDecor& ref)
	: MapObject(ref.topLeft, ref.model),
	pathing(ref.pathing)
{
}

EmoteDecor& EmoteDecor::operator=(const EmoteDecor& ref)
{
	topLeft = ref.topLeft;
	model = ref.model;
	pathing = ref.pathing;
	return *this;
}
