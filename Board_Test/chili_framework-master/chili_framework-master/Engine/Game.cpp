/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    board(Board()),
    dude(EmoteHuman(Vec2(379.0f, 279.0f), Colors::Yellow))
{
    map = mapTest;
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    // acquire delta time between this frame and last frame
    float dt = ft.getFrameDeltaTime();
    // screen movement input reading
    float xScroll = 0.0f;
    float yScroll = 0.0f;
    if (wnd.kbd.KeyIsPressed(VK_DOWN))
    {
        yScroll = 1.0f;
    }
    if (wnd.kbd.KeyIsPressed(VK_UP))
    {
        yScroll = -1.0f;
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT))
    {
        xScroll = -1.0f;
    }
    if (wnd.kbd.KeyIsPressed(VK_RIGHT))
    {
        xScroll = 1.0f;
    }
    board.update(xScroll, yScroll, dt);
    if (wnd.kbd.KeyIsPressed('D'))
    {
        bool dude = true;
    }
}

void Game::drawBackground()
{
    std::pair<int, int> rowCol = board.rowColToDraw();
    int startId = board.pos2Id(board.getCamTopLeft());
    for (int i = 0; i < rowCol.second; i++)
    {
        for (int j = 0; j < rowCol.first; j++)
        {
            int tileId = i * BrdData::Columns + startId + j;
            TilePortion visibleArea = board.getVisibleArea(tileId);
            gfx.DrawRect(visibleArea.topLeft, visibleArea.bottomRight, map[tileId]);
        }
    }
}

void Game::ComposeFrame()
{
    drawBackground();
    board.draw(gfx);
    dude.drawObject(gfx);
}
