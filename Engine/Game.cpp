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
	gfx( wnd )
{
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
	if ((winLeft || winRight) && wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		ball0PosX = gfx.ScreenWidth * 0.5;
		ball0PosY = gfx.ScreenHeight * 0.5;
		ball0VelX = 0;
		ball0VelY = 0;
		ball1PosX = gfx.ScreenWidth * 0.6;
		ball1PosY = gfx.ScreenHeight * 0.6;
		ball1VelX = 0;
		ball1VelY = 0;
		ball2PosX = gfx.ScreenWidth * 0.4;
		ball2PosY = gfx.ScreenHeight * 0.4;
		ball2VelX = 0;
		ball2VelY = 0;
		ballNum = 0;
		ballNumChosen = false;
		ballVelAddX = 0;
		ballVelAddChosen = false;
		player0PosX = 1;
		player0PosY = gfx.ScreenHeight * 0.4;
		player1PosX = gfx.ScreenWidth - 5;
		player1PosY = gfx.ScreenHeight * 0.4;
		player2PosX = 1;
		player2PosY = gfx.ScreenHeight * 0.6;
		player3PosX = gfx.ScreenWidth - 5;
		player3PosY = gfx.ScreenHeight * 0.6;
		playerNum = 0;
		playerNumChosen = false;
		winLeft = false;
		winRight = false;
	}
	if (!winLeft && !winRight)
	{
		if (wnd.kbd.KeyIsPressed(0x31) && !playerNumChosen)
		{
			playerNum = 0;
			playerNumChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(0x32) && !playerNumChosen)
		{
			playerNum = 1;
			playerNumChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD7) && playerNumChosen && !ballNumChosen)
		{
			ballNum = 0;
			ballNumChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD8) && playerNumChosen && !ballNumChosen)
		{
			ballNum = 1;
			ballNumChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD9) && playerNumChosen && !ballNumChosen)
		{
			ballNum = 2;
			ballNumChosen = true;
		}

		if (wnd.kbd.KeyIsPressed(VK_NUMPAD0) && ballNumChosen && !ballVelAddChosen)
		{
			ballVelAddX = 1;
			ballVelAddChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD1) && ballNumChosen && !ballVelAddChosen)
		{
			ballVelAddX = 2;
			ballVelAddChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD2) && ballNumChosen && !ballVelAddChosen)
		{
			ballVelAddX = 3;
			ballVelAddChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD3) && ballNumChosen && !ballVelAddChosen)
		{
			ballVelAddX = 4;
			ballVelAddChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD4) && ballNumChosen && !ballVelAddChosen)
		{
			ballVelAddX = 5;
			ballVelAddChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD5) && ballNumChosen && !ballVelAddChosen)
		{
			ballVelAddX = 6;
			ballVelAddChosen = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD6) && ballNumChosen && !ballVelAddChosen)
		{
			ballVelAddX = 7;
			ballVelAddChosen = true;
		}

		if (ballVelAddChosen && ball0VelX == 0 && ball1VelX == 0 && ball2VelX == 0)
		{
			ball0VelX = ballVelAddX;
			ball1VelX = -ballVelAddX;
			ball2VelX = ballVelAddX;
		}

		if (wnd.kbd.KeyIsPressed(0x53) && ballVelAddChosen)
		{
			player0PosY = PlayerDown(player0PosY);
		}
		if (wnd.kbd.KeyIsPressed(0x51) && ballVelAddChosen)
		{
			player0PosY = PlayerUp(player0PosY);
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD5) && ballVelAddChosen)
		{
			player1PosY = PlayerDown(player1PosY);
		}
		if (wnd.kbd.KeyIsPressed(VK_NUMPAD9) && ballVelAddChosen)
		{
			player1PosY = PlayerUp(player1PosY);
		}
		if (playerNum > 0)
		{
			if (wnd.kbd.KeyIsPressed(0x44) && ballVelAddChosen)
			{
				player2PosY = PlayerDown(player2PosY);
			}
			if (wnd.kbd.KeyIsPressed(0x57) && ballVelAddChosen)
			{
				player2PosY = PlayerUp(player2PosY);
			}
			if (wnd.kbd.KeyIsPressed(VK_NUMPAD4) && ballVelAddChosen)
			{
				player3PosY = PlayerDown(player3PosY);
			}
			if (wnd.kbd.KeyIsPressed(VK_NUMPAD8) && ballVelAddChosen)
			{
				player3PosY = PlayerUp(player3PosY);
			}
		}

		ball0PosX = ballXPosition(ball0PosX, ball0VelX);
		ball0PosX = ballXBorder(ball0PosX);
		ball0VelX = ballXBounce(ball0PosX, ball0VelX);
		ball0VelX = ballXVelAdd(ball0PosX, ball0VelX, ballVelAddX);
		ball0PosY = ballYPosition(ball0PosY, ball0VelY);
		ball0PosY = ballYBorder(ball0PosY);
		ball0VelY = ballYBounce(ball0PosY, ball0VelY);
		ball0VelY = ballYVellAddLeft(player0PosY, ball0PosX, ball0PosY, ball0VelY);
		ball0VelY = ballYVellAddRight(player1PosY, ball0PosX, ball0PosY, ball0VelY);
		if (playerNum > 0)
		{
			ball0VelY = ballYVellAddLeft(player2PosY, ball0PosX, ball0PosY, ball0VelY);
			ball0VelY = ballYVellAddRight(player3PosY, ball0PosX, ball0PosY, ball0VelY);
		}
		winLeft = lostRight(ball0PosX, ball0PosY);
		winRight = lostLeft(ball0PosX, ball0PosY);
		if (ballNum > 0)
		{
			ball1PosX = ballXPosition(ball1PosX, ball1VelX);
			ball1PosX = ballXBorder(ball1PosX);
			ball1VelX = ballXBounce(ball1PosX, ball1VelX);
			ball1VelX = ballXVelAdd(ball1PosX, ball1VelX, ballVelAddX);
			ball1PosY = ballYPosition(ball1PosY, ball1VelY);
			ball1PosY = ballYBorder(ball1PosY);
			ball1VelY = ballYBounce(ball1PosY, ball1VelY);
			ball1VelY = ballYVellAddLeft(player0PosY, ball1PosX, ball1PosY, ball1VelY);
			ball1VelY = ballYVellAddRight(player1PosY, ball1PosX, ball1PosY, ball1VelY);
			if (playerNum > 0)
			{
				ball1VelY = ballYVellAddLeft(player2PosY, ball1PosX, ball1PosY, ball1VelY);
				ball1VelY = ballYVellAddRight(player3PosY, ball1PosX, ball1PosY, ball1VelY);
			}
			winLeft = lostRight(ball1PosX, ball1PosY);
			winRight = lostLeft(ball1PosX, ball1PosY);
		}
		if (ballNum > 1)
		{
			ball2PosX = ballXPosition(ball2PosX, ball2VelX);
			ball2PosX = ballXBorder(ball2PosX);
			ball2VelX = ballXBounce(ball2PosX, ball2VelX);
			ball2VelX = ballXVelAdd(ball2PosX, ball2VelX, ballVelAddX);
			ball2PosY = ballYPosition(ball2PosY, ball2VelY);
			ball2PosY = ballYBorder(ball2PosY);
			ball2VelY = ballYBounce(ball2PosY, ball2VelY);
			ball2VelY = ballYVellAddLeft(player0PosY, ball2PosX, ball2PosY, ball2VelY);
			ball2VelY = ballYVellAddRight(player1PosY, ball2PosX, ball2PosY, ball2VelY);
			if (playerNum > 0)
			{
				ball2VelY = ballYVellAddLeft(player2PosY, ball2PosX, ball2PosY, ball2VelY);
				ball2VelY = ballYVellAddRight(player3PosY, ball2PosX, ball2PosY, ball2VelY);
			}
			winLeft = lostRight(ball2PosX, ball2PosY);
			winRight = lostLeft(ball2PosX, ball2PosY);
		}
	}
}

void Game::ComposeFrame()
{
	if (!winLeft && !winRight)
	{
		RenderPlayer(player0PosX, player0PosY, 0, 0, 255);
		RenderPlayer(player1PosX, player1PosY, 0, 0, 255);
		if (playerNum > 0)
		{
			RenderPlayer(player2PosX, player2PosY, 0, 255, 0);
			RenderPlayer(player3PosX, player3PosY, 0, 255, 0);
		}

		RenderBall(ball0PosX, ball0PosY, 0, 255, 255);
		if (ballNum > 0)
		{
			RenderBall(ball1PosX, ball1PosY, 255, 0, 255);
		}
		if (ballNum > 1)
		{
			RenderBall(ball2PosX, ball2PosY, 255, 255, 0);
		}
	}

	if (winLeft)
	{
		winSimbol(20, gfx.ScreenHeight / 2, 255, 215, 0);
	}
	if (winRight)
	{
		winSimbol(gfx.ScreenWidth - 21, gfx.ScreenHeight / 2, 255, 215, 0);
	}
}
void Game::RenderPlayer(int palayer_pos_x, int player_pos_y, int player_r, int player_g, int player_b)
{
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 60, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 59, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 58, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 57, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 56, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 55, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 54, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 53, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 52, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 51, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 50, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 49, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 48, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 47, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 46, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 45, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 44, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 43, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 42, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 41, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 40, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 39, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 38, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 37, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 36, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 35, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 34, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 33, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 32, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 31, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 30, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 29, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 28, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 27, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 26, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 25, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 24, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 23, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 22, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 21, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 20, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 19, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 18, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 17, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 16, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 15, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 14, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 13, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 12, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 11, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 10, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 9, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 8, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 7, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 6, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 5, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 4, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 3, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 2, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y + 1, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 1, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 2, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 3, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 4, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 5, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 6, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 7, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 8, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 9, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 10, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 11, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 12, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 13, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 14, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 15, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 16, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 17, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 18, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 19, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 20, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 21, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 22, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 23, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 24, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 25, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 26, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 27, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 28, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 29, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 30, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 31, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 32, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 33, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 34, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 35, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 36, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 37, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 38, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 39, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 40, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 41, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 42, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 43, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 44, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 45, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 46, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 47, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 48, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 49, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 50, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 51, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 52, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 53, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 54, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 55, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 56, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 57, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 58, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x + 1, player_pos_y - 59, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 60, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 60, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 59, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 58, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 57, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 56, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 55, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 54, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 53, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 52, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 51, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 50, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 49, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 48, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 47, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 46, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 45, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 44, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 43, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 42, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 41, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 40, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 39, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 38, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 37, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 36, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 35, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 34, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 33, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 32, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 31, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 30, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 29, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 28, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 27, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 26, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 25, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 24, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 23, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 22, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 21, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 20, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 19, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 18, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 17, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 16, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 15, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 14, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 13, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 12, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 11, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 10, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 9, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 8, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 7, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 6, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 5, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 4, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 3, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 2, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y + 1, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 1, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 2, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 3, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 4, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 5, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 6, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 7, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 8, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 9, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 10, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 11, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 12, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 13, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 14, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 15, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 16, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 17, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 18, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 19, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 20, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 21, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 22, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 23, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 24, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 25, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 26, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 27, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 28, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 29, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 30, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 31, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 32, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 33, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 34, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 35, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 36, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 37, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 38, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 39, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 40, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 41, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 42, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 43, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 44, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 45, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 46, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 47, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 48, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 49, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 50, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 51, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 52, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 53, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 54, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 55, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 56, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 57, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 58, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 59, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x, player_pos_y - 60, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 60, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 59, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 58, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 57, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 56, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 55, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 54, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 53, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 52, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 51, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 50, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 49, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 48, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 47, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 46, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 45, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 44, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 43, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 42, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 41, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 40, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 39, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 38, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 37, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 36, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 35, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 34, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 33, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 32, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 31, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 30, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 29, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 28, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 27, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 26, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 25, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 24, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 23, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 22, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 21, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 20, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 19, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 18, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 17, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 16, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 15, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 14, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 13, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 12, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 11, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 10, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 9, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 8, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 7, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 6, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 5, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 4, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 3, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 2, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y + 1, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 1, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 2, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 3, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 4, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 5, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 6, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 7, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 8, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 9, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 10, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 11, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 12, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 13, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 14, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 15, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 16, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 17, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 18, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 19, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 20, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 21, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 22, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 23, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 24, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 25, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 26, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 27, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 28, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 29, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 30, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 31, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 32, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 33, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 34, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 35, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 36, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 37, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 38, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 39, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 40, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 41, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 42, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 43, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 44, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 45, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 46, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 47, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 48, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 49, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 50, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 51, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 52, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 53, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 54, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 55, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 56, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 57, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 58, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 59, player_r, player_g, player_b);
	gfx.PutPixel(palayer_pos_x - 1, player_pos_y - 60, player_r, player_g, player_b);
}
int Game::PlayerDown(int player_pos_y)
{
	if (player_pos_y <= gfx.ScreenHeight - 61)
	{
		player_pos_y = player_pos_y + 10;
	}
	if (player_pos_y > gfx.ScreenHeight - 61)
	{
		player_pos_y = gfx.ScreenHeight - 61;
	}
	return player_pos_y;
}
int Game::PlayerUp(int player_pos_y)
{
	if (player_pos_y >= 60)
	{
		player_pos_y = player_pos_y - 10;
	}
	if (player_pos_y < 60)
	{
		player_pos_y = 60;
	}
	return player_pos_y;
}
void Game::RenderBall(int ball_pos_x, int ball_pos_y, int ball_r, int ball_g, int ball_b)
{
	gfx.PutPixel(ball_pos_x, ball_pos_y, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x, ball_pos_y + 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x, ball_pos_y + 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x, ball_pos_y - 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x, ball_pos_y - 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 1, ball_pos_y, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 1, ball_pos_y + 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 1, ball_pos_y + 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 1, ball_pos_y - 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 1, ball_pos_y - 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 2, ball_pos_y, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 2, ball_pos_y + 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 2, ball_pos_y + 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 2, ball_pos_y - 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 2, ball_pos_y - 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 1, ball_pos_y, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 1, ball_pos_y + 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 1, ball_pos_y + 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 1, ball_pos_y - 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 1, ball_pos_y - 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 2, ball_pos_y, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 2, ball_pos_y + 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 2, ball_pos_y + 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 2, ball_pos_y - 1, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 2, ball_pos_y - 2, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x, ball_pos_y + 3, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x, ball_pos_y - 3, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x + 3, ball_pos_y, ball_r, ball_g, ball_b);
	gfx.PutPixel(ball_pos_x - 3, ball_pos_y, ball_r, ball_g, ball_b);
}

int Game::ballXPosition(int ball_pos_x, int ball_vel_x)
{
	ball_pos_x = ball_pos_x + ball_vel_x;
	return ball_pos_x;
}

int Game::ballXBorder(int ball_pos_x)
{
	if (ball_pos_x < 3)
	{
		ball_pos_x = 3;
	}
	else if (ball_pos_x > gfx.ScreenWidth - 4)
	{
		ball_pos_x = gfx.ScreenWidth - 4;
	}
	else
	{
		ball_pos_x = ball_pos_x;
	}
	return ball_pos_x;
}

int Game::ballXBounce(int ball_pos_x, int ball_vel_x)
{
	if (ball_pos_x <= 3 || ball_pos_x >= gfx.ScreenWidth - 4)
	{
		ball_vel_x = -ball_vel_x;
	}
	else
	{
		ball_vel_x = ball_vel_x;
	}
	return ball_vel_x;
}

int Game::ballXVelAdd(int ball_pos_x, int ball_vel_x, int ball_vel_add)
{
	if(ball_pos_x <= 3 && ball_vel_x < ball_vel_add * 4)
	{
		ball_vel_x = ball_vel_x + ball_vel_add;
	}
	else if (ball_pos_x >= gfx.ScreenWidth - 4 && ball_vel_x > ball_vel_add * -4)
	{
		ball_vel_x = ball_vel_x - ball_vel_add;
	}
	else
	{
	ball_vel_x = ball_vel_x;
	}
	return ball_vel_x;
}

int Game::ballYPosition(int ball_pos_y, int ball_vel_y)
{
	ball_pos_y = ball_pos_y + ball_vel_y;
	return ball_pos_y;
}

int Game::ballYBorder(int ball_pos_y)
{
	if (ball_pos_y < 3)
	{
		ball_pos_y = 3;
	}
	else if (ball_pos_y > gfx.ScreenHeight - 4)
	{
		ball_pos_y = gfx.ScreenHeight - 4;
	}
	else
	{
		ball_pos_y = ball_pos_y;
	}
	return ball_pos_y;
}

int Game::ballYBounce(int ball_pos_y, int ball_vel_y)
{
	if (ball_pos_y <= 3 || ball_pos_y >= gfx.ScreenHeight - 4)
	{
		ball_vel_y = - ball_vel_y;
	}
	else
	{
		ball_vel_y = ball_vel_y;
	}
	return ball_vel_y;
}

int Game::ballYVellAddLeft(int player_pos_y, int ball_pos_x, int ball_pos_y, int ball_vel_y)
{
	if (ball_pos_x == 3 && player_pos_y + 62 > ball_pos_y && player_pos_y - 62 < ball_pos_y)
	{
		ball_vel_y = ball_vel_y + (ball_pos_y - player_pos_y) / 20;
	}
	else
	{
		ball_vel_y = ball_vel_y;
	}
	return ball_vel_y;
}

int Game::ballYVellAddRight(int player_pos_y, int ball_pos_x, int ball_pos_y, int ball_vel_y)
{
	if (ball_pos_x == gfx.ScreenWidth - 4 && player_pos_y + 62 > ball_pos_y && player_pos_y - 62 < ball_pos_y)
	{
		ball_vel_y = ball_vel_y + (ball_pos_y - player_pos_y) / 20;
	}
	else
	{
		ball_vel_y = ball_vel_y;
	}
	return ball_vel_y;
}

bool Game::lostLeft(int ball_pos_x, int ball_pos_y)
{
	if (ball_pos_x == 3 && playerNum == 0 &&
		(player0PosY + 62 <= ball_pos_y || player0PosY - 62 >= ball_pos_y))
	{
		return true;
	}
	else if (ball_pos_x == 3 && playerNum == 1 &&
		((player0PosY + 62 <= ball_pos_y || player0PosY - 62 >= ball_pos_y) &&
		(player2PosY + 62 <= ball_pos_y || player2PosY - 62 >= ball_pos_y)))
	{
		return true;
	}
	else if (!winRight)
	{
		return false;
	}
	else if (winRight)
	{
		return true;
	}
}

bool Game::lostRight(int ball_pos_x, int ball_pos_y)
{
	if (ball_pos_x == gfx.ScreenWidth - 4 && playerNum == 0 &&
		(player1PosY + 62 <= ball_pos_y || player1PosY - 62 >= ball_pos_y))
	{
		return true;
	}
	else if (ball_pos_x == gfx.ScreenWidth - 4 && playerNum == 1 &&
		((player1PosY + 62 <= ball_pos_y || player1PosY - 62 >= ball_pos_y) &&
		(player3PosY + 62 <= ball_pos_y || player3PosY - 62 >= ball_pos_y)))
	{
		return true;
	}
	else if (!winLeft)
	{
		return false;
	}
	else if (winLeft)
	{
		return true;
	}
}

void Game::winSimbol(int win_simbol_pos_x, int win_simbol_pos_y, int win_simbol_r, int win_simbol_g, int win_simbol_b)
{
	gfx.PutPixel(win_simbol_pos_x - 6, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 5, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 4, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 3, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 2, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 1, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 1, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 2, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 3, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 4, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 5, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 6, win_simbol_pos_y + 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 6, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 5, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 4, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 3, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 2, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 1, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 1, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 2, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 3, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 4, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 5, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 6, win_simbol_pos_y, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 6, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 5, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 4, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 2, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 1, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 1, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 2, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 4, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 5, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 6, win_simbol_pos_y - 1, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 6, win_simbol_pos_y - 2, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 5, win_simbol_pos_y - 2, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 1, win_simbol_pos_y - 2, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x, win_simbol_pos_y - 2, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 1, win_simbol_pos_y - 2, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 5, win_simbol_pos_y - 2, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 6, win_simbol_pos_y - 2, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x - 6, win_simbol_pos_y - 3, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x, win_simbol_pos_y - 3, win_simbol_r, win_simbol_g, win_simbol_b);
	gfx.PutPixel(win_simbol_pos_x + 6, win_simbol_pos_y - 3, win_simbol_r, win_simbol_g, win_simbol_b);


}
