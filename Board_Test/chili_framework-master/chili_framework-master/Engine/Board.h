#pragma once
#include "Screen.h"


class Board
{
private:
	// methods
	void DrawMargin(const Vec2& topLeft, const Vec2& bottomRight, Graphics& gfx);
public:
	// methods
	Board();
	~Board();

	int pos2Id(const Vec2& point);
	void update(float camXscroll, float camYscroll, float deltaTime);
	void draw(Graphics& gfx);
	void toggleGridView();
	std::pair<int,int> rowColToDrawFromTopLeft();
private:
// ___________
	// inner class
	class BoardTile
	{
	public:
		// methods
		BoardTile(int Id);
		~BoardTile();

		TilePortion getVisiblePart(const Vec2& cameraTopLeft);
		void drawPerimeter(const Vec2& cameraTopLeft, Graphics& gfx, Color gridColor);
		Vec2 getTopLeft();
		Vec2 getBottomRight();
	private:
		//members
		int id;
	};
// ----------
private:
	//members
	std::vector<BoardTile> listTiles;
	Screen camera;
	bool gridViewable;
	Color gridColor;
};