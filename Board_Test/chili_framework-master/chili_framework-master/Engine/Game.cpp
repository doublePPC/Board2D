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
    eGame(EmoteGame())
{
}

void Game::Go()
{
	gfx.BeginFrame();
    float dt = ft.getFrameDeltaTime();
    while (dt > 0.0f)
    {
        const float framePart = std::min(0.0025f, dt);
        UpdateModel(framePart);
        dt -= framePart;
    }
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float frameTimeFragment)
{
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
    eGame.update(xScroll, yScroll, frameTimeFragment);
    if (wnd.kbd.KeyIsPressed('D'))
    {
        bool dude = true;
    }
}

void Game::ComposeFrame()
{
    eGame.drawMap(gfx);
}
