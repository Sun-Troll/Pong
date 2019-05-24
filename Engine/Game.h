/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void RenderPlayer(int palayer_pos_x, int player_pos_y, int player_r, int player_g, int player_b);
	int PlayerDown(int player_pos_y);
	int PlayerUp(int player_pos_y);
	void RenderBall(int ball_pos_x, int ball_pos_y, int ball_r, int ball_g, int ball_b);
	int ballXPosition(int ball_pos_x,int ball_vel_x);
	int ballXBorder(int ball_pos_x);
	int ballXBounce(int ball_pos_x, int ball_vel_x);
	int ballXVelAdd(int ball_pos_x, int ball_vel_x, int ball_vel_add);
	int ballYPosition(int ball_pos_y, int ball_vel_y);
	int ballYBorder(int ball_pos_y);
	int ballYBounce(int ball_pos_y, int ball_vel_y);
	int ballYVellAddLeft(int player_pos_y, int ball_pos_x, int ball_pos_y, int ball_vel_y);
	int ballYVellAddRight(int player_pos_y, int ball_pos_x, int ball_pos_y, int ball_vel_y);
	bool lostLeft(int ball_pos_x, int ball_pos_y);
	bool lostRight(int ball_pos_x, int ball_pos_y);
	void winSimbol(int win_simbol_pos_x,int win_simbol_pos_y, int win_simbol_r, int win_simbol_g, int win_simbol_b);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int ball0PosX = gfx.ScreenWidth * 0.5;
	int ball0PosY = gfx.ScreenHeight * 0.5;
	int ball0VelX = 0;
	int ball0VelY = 0;
	int ball1PosX = gfx.ScreenWidth * 0.6;
	int ball1PosY = gfx.ScreenHeight * 0.6;
	int ball1VelX = 0;
	int ball1VelY = 0;
	int ball2PosX = gfx.ScreenWidth * 0.4;
	int ball2PosY = gfx.ScreenHeight * 0.4;
	int ball2VelX = 0;
	int ball2VelY = 0;
	int ballNum = 0;
	bool ballNumChosen = false;
	int ballVelAddX = 0;
	bool ballVelAddChosen = false;
	int player0PosX = 1;
	int player0PosY = gfx.ScreenHeight * 0.4;
	int player1PosX = gfx.ScreenWidth -5;
	int player1PosY = gfx.ScreenHeight * 0.4;
	int player2PosX = 1;
	int player2PosY = gfx.ScreenHeight * 0.6;
	int player3PosX = gfx.ScreenWidth - 5;
	int player3PosY = gfx.ScreenHeight * 0.6;
	int playerNum = 0;
	bool playerNumChosen = false;
	bool winLeft = false;
	bool winRight = false;
	/********************************/
};