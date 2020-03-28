#pragma once
#include "Screen.h"
#include <vector>

class Board
{
public:
	// methods
	Board();
	~Board();


private:
// ___________
	// inner class
	class BoardTile
	{
	public:
		// methods
		BoardTile(int xId, int yId);
		~BoardTile();

	private:
		BoardTile();
		//members
		Vec2 topLeft;
		Vec2 bottomRight;
	public:
		//constants
		static constexpr int tileWidth = 100;
		static constexpr int tileHeight = 100;
	};
// ----------

private:
	//members
	std::vector<BoardTile> listTiles;
	Screen camera;
public:
	//constants
	static constexpr int width = 16;
	static constexpr int height = 16;
};