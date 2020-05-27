#pragma once

#include "Sounds_Graphics\\Graphics.h"
#include "Generic\\Vec2.h"

class SpriteCodex
{
public:
	// Chili Stuff

	// centered drawing of 14x14 sprite
	static void DrawBall(const Vec2& center, Graphics& gfx);
	// centered drawing of 200x160 sprite
	static void DrawTitle(const Vec2& center, Graphics& gfx);
	// centered drawing of 84x64 sprite
	static void SpriteCodex::DrawGameOver(const Vec2& center, Graphics& gfx);
	// centered drawing of 104x19 sprite
	static void SpriteCodex::DrawReady(const Vec2& center, Graphics& gfx);
	// centered drawing of 24x24 sprite
	static void SpriteCodex::DrawPoo(const Vec2& center, Graphics& gfx);

	// Sidewalk Stuff

	// emote base human circle of 42x42 size
	static void DrawCircle(const Vec2& topLeft, Graphics& gfx, Color baseColor);
};