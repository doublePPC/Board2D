#pragma once
#include "Board.h"
#include "EmoteHuman.h"

class EmoteGame
{
public:
	EmoteGame();
	~EmoteGame();

	void update(float dt);
	void draw(Graphics& gfx);
private:
	Board board;

};