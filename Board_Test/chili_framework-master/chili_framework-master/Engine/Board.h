#pragma once
#include "Screen.h"
#include <vector>


class Board
{
private:
	// methods
	int DrawLign(int lign, Graphics& gfx);
	void DrawMargin(const Vec2& topLeft, const Vec2& bottomRight, Graphics& gfx);
	
public:
	// methods
	Board();
	~Board();

	int x2Id(const Vec2& point);
	int y2Id(const Vec2& point);
	void update(float camXscroll, float camYscroll, float deltaTime);
	void drawBoard(Graphics& gfx);
private:
// ___________
	// inner class
	class BoardTile
	{
	public:
		// methods
		BoardTile(int xId, int yId);
		~BoardTile();

		int drawTile(const Vec2& topLeft, const Vec2& bottomRight, Graphics& gfx);
		void drawPerimeter(const Vec2& topLeft, const Vec2& bottomRight, Graphics& gfx);
	private:
		BoardTile();
		//members
		int xId;
		int yId;
	public:
		//constants
		static constexpr int tileWidth = 100;
		static constexpr int tileHeight = 100;
	};
// ----------

private:
	//members
	std::vector<std::vector<BoardTile>> listTiles;  // bi-dimensional vector, first index is X coordinate (columns) and second is Y coordinate (ligns)
	Screen camera;
public:
	//constants
	static constexpr int width = 16;
	static constexpr int height = 16;
};