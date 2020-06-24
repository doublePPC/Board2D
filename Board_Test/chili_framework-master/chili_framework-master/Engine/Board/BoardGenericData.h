#pragma once
#include "..\\Sounds_Graphics\\Graphics.h"
#include "..\\Generic\\Bit2DataConverter.h"
#include <vector>

// this header file contains structs for data transportation from class to class about board datas

enum class visibilityStatus
{
	off = 0,
	total = 1,
	partTop = 2,
	partBottom = 3,
	partLeft = 4,
	partRight = 5,
	partTL = 24,
	partTR = 25,
	partBL = 34,
	partBR = 35
};

visibilityStatus isRectVisible(const Vec2& topLeftPos, const Vec2& botRightPos);
bool isVecVisible(const Vec2& vec);
Vec2 visibleTopLeft(const Vec2& convertedTL, visibilityStatus status);
Vec2 visibleBottomRight(const Vec2& convertedBR, visibilityStatus status);

struct BrdData
{
	int Columns;
	int Rows;
	int Tile_Width;
	int Tile_Height;
	Color Grid_DefaultColor;

	static const int Cam_X_Size = Graphics::ScreenWidth -100;
	static const int Cam_Y_Size = Graphics::ScreenHeight;
	static const int Cam_Speed = 600;
	static const bool Grid_DefaultViewable = false;
};


// data structs
struct TilePortion
{
	Vec2 topLeft;
	Vec2 bottomRight;
};