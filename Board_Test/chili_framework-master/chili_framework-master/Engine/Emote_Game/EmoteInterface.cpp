#include "EmoteInterface.h"

e_Interface::e_Interface(Color back, const Vec2& top, const Vec2& bot)
	: background(back),
	topLeft(top),
	bottomRight(bot)
{
}

void e_Interface::update()
{
}

void e_Interface::draw(Graphics& gfx)
{
	gfx.DrawRect(topLeft, bottomRight, background);
}
