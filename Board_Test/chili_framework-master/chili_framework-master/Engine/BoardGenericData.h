#pragma once
#include "Graphics.h"
#include <vector>
#include <map>

// this header file contains structs for data transportation from class to class about board datas

// constants
struct BrdData
{
	int Columns;
	int Rows;
	int Tile_Width;
	int Tile_Height;
	Color Grid_DefaultColor;

	static const int Cam_X_Size = Graphics::ScreenWidth;
	static const int Cam_Y_Size = Graphics::ScreenHeight;
	static const int Cam_Speed = 120;
	static const bool Grid_DefaultViewable = true;
};


// data structs
struct TilePortion
{
	Vec2 topLeft;
	Vec2 bottomRight;
};