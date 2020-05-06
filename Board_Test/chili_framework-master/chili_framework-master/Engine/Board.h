#pragma once
#include "Screen.h"


class Board
{
public:
	Board() = default;
	Board(BrdData initData);
	Board(const Board& refBrd);
	Board& operator= (const Board& refBrd);
	~Board();

	// Board methods
	const Vec2& getCamTopLeft();
	int pos2Id(const Vec2& point);
	void update(float camXscroll, float camYscroll, float deltaTime);
	void draw(Graphics& gfx);
	void toggleGridView();
	std::pair<int,int> rowColToDraw();

	// Tiles methods
	Vec2 getTileConvTL(int index);
	TilePortion getVisiblePart(int index);
	void drawPerimeter(int index, Graphics& gfx);
	Vec2 getTopLeft(int index);
	Vec2 getBottomRight(int index);
private:
	int columns;
	int rows;
	int tileWidth;
	int tileHeight;
	Screen camera;
	bool gridViewable;
	Color gridColor;
};