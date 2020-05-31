#pragma once
#include "EmoteGenericData.h"

class e_Interface
{
public:
	e_Interface() = delete;
	e_Interface(Color back, const Vec2& top, const Vec2& bot);
	~e_Interface() = default;

	void update();
	void draw(Graphics& gfx);
private:
	Color background;
	Vec2 topLeft;
	Vec2 bottomRight;
};