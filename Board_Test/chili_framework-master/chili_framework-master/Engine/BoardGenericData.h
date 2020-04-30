#pragma once
#include "Graphics.h"
#include <vector>
#include <map>

// this header file contains includes, constants and datastructs needed for the board algorithm

// constants
struct BrdData
{
	static const int Columns = 16;
	static const int Rows = 16;
	static const int Tile_Width = 100;
	static const int Tile_Height = 100;
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