/*Brick::setBrickCount(110);
		bricks = new Brick[Brick::getBrickCount()];
		foods = new Food[Brick::getBrickCount()];
		int k = 0;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				bricks[k].setColor(GetRandInRange(0, powerUpTypes));
				foods[k].setColor(bricks[k].getColor());
				bricks[k].setHealth();
				bricks[k].setXPos(wallWidth + brickLength + brickLength * j);
				bricks[k].setYPos((840 - brickHeight * 12) - wallWidth + brickHeight * i);
				foods[k].setXPos(bricks[k].getXPos());
				foods[k].setYPos(bricks[k].getYPos());
				k++;
			}
		}

		balls = new Ball[1];
		(*balls)++;

		paddle = new Paddle[1];*/

#ifndef GAME_H
#define GAME_H

#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt

#include "abstract.h"
#include "ball.h"
#include "brick.h"
#include "food.h"
#include "paddle.h"

using namespace std;

class Game
{
private:
	int level;
	int lives;

	Brick* bricks;
	int brickLength;
	int brickHeight;

	Ball* balls;

	Paddle* paddle;

	int wallWidth;

	int powerUpTypes;
	Food *foods;

	int score;

public:
	Game() : wallWidth(30), powerUpTypes(5), score(0), level(0), lives(0)
	{
		brickLength = 80;
		brickHeight = 30;

		Brick::setBrickCount(110);
		bricks = nullptr;
		foods = nullptr;

		balls = nullptr;
		paddle = nullptr;

		//cout << "intialised" << endl;
	}

	int getLevel() const { return level; }

	void setLevel(int l)
	{
		level = l;
	}

	void level1()
	{
		Brick::setBrickCount(110);
		bricks = new Brick[Brick::getBrickCount()];
		foods = new Food[Brick::getBrickCount()];
		int k = 0;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				bricks[k].setColor(GetRandInRange(0, powerUpTypes));
				foods[k].setColor(bricks[k].getColor());
				bricks[k].setHealth();
				bricks[k].setXPos(wallWidth + brickLength + brickLength * j);
				bricks[k].setYPos((840 - brickHeight * 12) - wallWidth + brickHeight * i);
				foods[k].setXPos(bricks[k].getXPos());
				foods[k].setYPos(bricks[k].getYPos());
				k++;
			}
		}

		balls = new Ball[1];
		(*balls)++;

		lives = 2;

		paddle = new Paddle[1];
	}

	void line(int i, int j, Brick &brick)
	{
		if (j >= 4)
			return;

		brick.setXPos(30 + brickLength * j * i * 5 * brickLength);
		brick.setYPos(780 - brickHeight * j * i * 5 * brickHeight);

		cout << '*';

		line(i, j + 1, brick);
	}

	void setPattern(int i, Brick &brick)
	{
		if (i >= 5)
			return;

		if (i <= 2)
			line(i, 0, brick);
		else if (i == 3)
			line(2, 0, brick);
		else if (i == 4)
			line(3, 0, brick);

		setPattern(i + 1, brick);
	}

	void level2()
	{
		Brick::setBrickCount(100);
		bricks = new Brick[Brick::getBrickCount()];
		foods = new Food[Brick::getBrickCount()];
		int k = 0;
		cout<< 'a';
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				bricks[k].setColor(GetRandInRange(0, powerUpTypes));
				foods[k].setColor(bricks[k].getColor());
				bricks[k].setHealth();
				setPattern(0, bricks[k]);
				cout << bricks[k].getXPos() << ' ' << bricks[k].getYPos() << endl;
				foods[k].setXPos(bricks[k].getXPos());
				foods[k].setYPos(bricks[k].getYPos());
				k++;
			}
		}
cout << 'b';
		balls = new Ball[1];
		(*balls)++;

		lives = 2;

		paddle = new Paddle[1];
	}

	void livesCheck()
	{
		if (balls[0].getYPos() < 0 || balls[0].getYPos() > 840)
		{
			lives--;
			if (lives != 0)
			{
				balls[0].setXPos(505);
				balls[0].setYPos(300);
			}
		}
	}

	void drawWall()
	{
		DrawRectangle(0, 0, 30, 840, colors[PINK]);
		DrawRectangle(990, 0, 30, 840, colors[PINK]);
	}

	void drawCeiling()
	{
		DrawRectangle(0, 810, 1020, 30, colors[PINK]);
	}

	bool conditionBallPaddle(Ball &ball)
	{
		return ball.getXPos() >= paddle[0].getXPos() && ball.getXPos() <= (paddle[0].getXPos() + paddle[0].getLength()) && ball.getYPos() >= paddle[0].getYPos() && (ball.getYPos() - ball.getRadius()) <= (paddle[0].getYPos() + paddle[0].getHeight());
	}

	double collisionAngle(Ball &ball, Paddle &paddle)
	{
		double max_pos = paddle.getLength();

		double pos = (paddle.getXPos() + max_pos) - ball.getXPos();

		double frac = pos / max_pos;

		double max = 160 * M_PI / 180;
		double min = 20 * M_PI / 180;

		double angle = min + frac * (max- min);

		if (pos > 0)
			angle = -angle;

		return angle;
	}

	void ballCollidePaddle()
	{
		for (int i = 0; i < Ball::getBallCount(); i++)
		{
			if (conditionBallPaddle(balls[i]))
			{
				double angle = collisionAngle(balls[i], paddle[0]);
				balls[i].setXSpeed(Ball::getMag() * cos(angle));
				balls[i].setYSpeed(-Ball::getMag() * sin(angle));

				double currMagnitude = sqrt(balls[i].getXSpeed() * balls[i].getXSpeed() + balls[i].getYSpeed() * balls[i].getYSpeed());
				double factor = Ball::getMag() / currMagnitude;

				balls[i].setXSpeed(balls[i].getXSpeed() * factor);
				balls[i].setYSpeed(balls[i].getYSpeed() * factor);

				paddle[0].setColor(balls[i].getColor());
			}
		}
	}

	void ballCollideWall()
	{
		for (int i = 0; i < Ball::getBallCount(); i++)
		{
			if ((balls[i].getXPos() - balls[i].getRadius()) <= 30 || (balls[i].getXPos() + balls[i].getRadius()) >= 1020 - 30)
				balls[i].setXSpeed(-balls[i].getXSpeed());
		}
	}

	void ballCollideCeiling()
	{
		for (int i = 0; i < Ball::getBallCount(); i++)
		{
			if (balls[i].getYPos() >= 840 - 30 - balls[i].getRadius())
				balls[i].setYSpeed(-balls[i].getYSpeed());
		}
	}

	bool conditionBallBrick(Brick &brick, Ball &ball)
	{
		return ball.getXPos() + ball.getRadius() >= brick.getXPos() && ball.getXPos() - ball.getRadius() <= brick.getXPos() + brickLength && ball.getYPos() + ball.getRadius() >= brick.getYPos() && ball.getYPos() - ball.getRadius() <= brick.getYPos() + brickHeight;
	}

	void ballCollideBrick()
	{
		for (int i = 0; i < Ball::getBallCount(); i++)
		{
			for (int j = 0; j < Brick::getBrickCount(); j++)
			{
				int x = balls[i].getXPos(), y = balls[i].getYPos();
				int radius = balls[i].getRadius();

				int b_x = bricks[j].getXPos(), b_y = bricks[j].getYPos();

				if (conditionBallBrick(bricks[j], balls[i]))
				{ // Update to consider 8 zones
					if (x + radius >= b_x && x - radius <= b_x + brickLength && y - radius <= b_y)
					{
						balls[i].setYSpeed(-balls[i].getYSpeed());
						balls[i].draw();
						balls[i].changeYPos(balls[i].getYSpeed());
					}
					else if (x + radius >= b_x && x - radius <= b_x + brickLength && y + radius >= b_y + brickHeight)
					{
						balls[i].setYSpeed(-balls[i].getYSpeed());
						balls[i].draw();
						balls[i].changeYPos(balls[i].getYSpeed());
					}
					else if (y + radius >= b_y && y - radius <= b_y+ brickHeight && x - radius <= b_x)
					{
						balls[i].setXSpeed(-balls[i].getXSpeed());
						balls[i].draw();
						balls[i].changeXPos(balls[i].getXSpeed());
					}
					else if (y + radius >= b_y && y - radius <= b_y + brickHeight && x + radius >= b_x + brickLength)
					{
						balls[i].setXSpeed(-balls[i].getXSpeed());
						balls[i].draw();
						balls[i].changeXPos(balls[i].getXSpeed());
					}
					else
					{
						balls[i].setYSpeed(-balls[i].getYSpeed());
						balls[i].setXSpeed(-balls[i].getXSpeed());
						balls[i].draw();
						balls[i].changeYPos(balls[i].getYSpeed());
						balls[i].changeXPos(balls[i].getXSpeed());
					}

					bricks[j]--;

					switch (bricks[j].getColor())
					{
					case 0:
						score += 5;
						break;
					case 1:
						score += 12;
						break;
					case 2:
						score += 27;
						break;
					case 3:
						score += 27;
						break;
					case 4:
						score += 12;
					}

					score += 2;

					balls[i].setColor(bricks[j].getColor());

					if (bricks[j].getHealth() <= 0)
						foods[j].setTrueMoving();

					break;
				}
			}
		}
	}

	void foodWithPaddle()
	{
		for (int i = 0; i < Brick::getBrickCount(); i++)
		{
			int x = foods[i].getXPos();
			int y = foods[i].getYPos();
			int p_x = paddle[0].getXPos();
			int p_y = paddle[0].getYPos();
			switch (foods[i].getColor())
			{
			case 0:
				if ((x + 22 >= p_x && x + 22 <= p_x + paddle[0].getLength() && y >= p_y && y <= p_y + paddle[0].getHeight()) || (x + 22 + 17 + 17 >= p_x && x + 22 + 17 + 17 <= p_x + paddle[0].getLength() && y >= p_y && y <= p_y + paddle[0].getHeight()) || (x + 22 + 17 >= p_x && x + 22 + 17 <= p_x + paddle[0].getLength() && y + 30 >= p_y && y + 30 <= p_y + paddle[0].getHeight()))
				{
					if (paddle[0].getLength() < 750)
					{
						paddle[0].setLength(paddle[0].getLength() * 2);
						paddle[0].setXPos(paddle[0].getXPos() - paddle[0].getLength()/4);
					}

					foods[i].setXPos(-333);
					foods[i].setYPos(-333);
				}
				break;
			case 1:
				if ((x + 25 >= p_x && x + 25 <= p_x + paddle[0].getLength() && y >= p_y && y <= p_y + paddle[0].getHeight()) || (x + 25 + 30 >= p_x && x + 25 + 30 <= p_x + paddle[0].getLength() && y >= p_y && y <= p_y + paddle[0].getHeight()) || (x + 25 >= p_x && x + 25 <= p_x + paddle[0].getLength() && y + 30 >= p_y && y + 30 <= p_y + paddle[0].getHeight()) || (x + 25 + 30 >= p_x && x + 25 + 30 <= p_x + paddle[0].getLength() && y + 30 >= p_y && y + 30 <= p_y + paddle[0].getHeight()))
				{
					if (paddle[0].getLength() > 30)
					{
						paddle[0].setLength(paddle[0].getLength() / 2);
						paddle[0].setXPos(paddle[0].getXPos() + paddle[0].getLength()/2);
					}

					foods[i].setXPos(-333);
					foods[i].setYPos(-333);
				}
				break;
			case 2:
				if ((x + 14 + 40 >= p_x && x + 14 + 40 <= p_x + paddle[0].getLength() && y + 15 - 14 >= p_y && y + 15 - 14 <= p_y + paddle[0].getHeight()) || (x + 40 - 14 >= p_x && x + 40 - 14 <= p_x + paddle[0].getLength() && y + 15 - 14 >= p_y && y + 15 - 14 <= p_y + paddle[0].getLength()) || (x + 40 + 14 >= p_x && x + 40+ 14 <= p_x + paddle[0].getLength() && y + 15 + 14 >= p_y && y + 15 + 14 <= p_y + paddle[0].getLength()) || (x + 40 - 14 >= p_x && x + 40 - 14 <= p_x + paddle[0].getLength() &&  y + 15 + 14 >= p_y && y + 15 + 14 <= p_y + paddle[0].getHeight()))
				{
					for (int j = 0; j < Ball::getBallCount(); j++)
					{
						balls[j].startPowerupTimer();
						if (Ball::getMag() - 2 >= 1)
							Ball::setMagnitude(Ball::getMag() - 2);
					}

					balls[0].setLast(1);

					foods[i].setXPos(-333);
					foods[i].setYPos(-333);
				}
				break;
			case 3:
				if ((x + 25 + 15 >= p_x && x + 25 + 15 <= p_x + paddle[0].getLength() && y >= p_y && y <= p_y + paddle[0].getHeight()) || (x + 15 >= p_x && x + 15 <= p_x + paddle[0].getLength() && y >= p_y && y <= p_y + paddle[0].getHeight()) || (x + 25 + 15 >= p_x && x + 25 + 15 <= p_x + paddle[0].getLength() && y + 30 >= p_y && y + 30 <= p_y + paddle[0].getHeight()) || (x + 15 >= p_x && x + 15 <= p_x + paddle[0].getLength() && y + 30 >= p_y && y + 30 <= p_y + paddle[0].getHeight()))
				{
					for (int j = 0; j < Ball::getBallCount(); j++)
					{
						balls[j].startPowerupTimer();
						if (Ball::getMag() + 2 <= 15)
							Ball::setMagnitude(Ball::getMag() + 2);
					}

					balls[0].setLast(2);

					foods[i].setXPos(-333);
					foods[i].setYPos(-333);
				}
				break;
			case 4:
				if ((x + 25 >= p_x && x + 25 <= p_x + paddle[0].getLength() && y >= p_y && y <= p_y + paddle[0].getHeight()) || (x + 25 + 30 >= p_x && x + 25 + 30 <= p_x + paddle[0].getLength() && y >= p_y && y <= p_y + paddle[0].getHeight()) || (x + 25 >= p_x && x + 25 <= p_x + paddle[0].getLength() && y + 30 >= p_y && y + 30 <= p_y + paddle[0].getHeight()) || (x + 25 + 30 >= p_x && x + 25 + 30 <= p_x + paddle[0].getLength() && y + 30 >= p_y && y + 30 <= p_y + paddle[0].getHeight()))
				{
					Ball *tempBalls = new Ball[Ball::getBallCount() + 2];

					for (int i = 0; i < Ball::getBallCount(); i++)
						tempBalls[i] = balls[i];

					int tempX = balls[0].getXPos();
					int tempY = balls[0].getYPos();

					tempBalls[Ball::getBallCount()] = balls[0];
					tempBalls[Ball::getBallCount() + 1] = balls[0];

					delete[] balls;

					(*balls)++;
					(*balls)++;

					balls = tempBalls;

					balls[0].setXPos(tempX);
					balls[0].setYPos(tempY);

					foods[i].setXPos(-333);
					foods[i].setYPos(-333);
				}
			}
		}
	}

	void powerUpFiveSeconds()
	{
		for (int i = 0; i < Ball::getBallCount(); i++)
		{
			if (balls[i].returnPowerupTimeElapsed() >= 5 && balls[i].returnPowerupTimeElapsed() <= 10)
			{
				if (balls[i].getLast() == 1)
					Ball::setMagnitude(5);
				else
					Ball::setMagnitude(5);

				balls[i].setPowerupTimeElapsed(100);
			}
		}
	}

	void controlBallCount()
	{
		for (int i = 1; i < Ball::getBallCount(); i++)
		{
			if (balls[i].returnCreationTimeElapsed() >= 5)
			{
				for (int j = i; j < Ball::getBallCount() - 1; j++)
				{
					balls[j] = balls[j + 1];
				}

				(*balls)--;
			}
		}
	}

	void updateLevel()
	{
		for (int i = 0; i < Ball::getBallCount(); i++)
			balls[i].updatePosition();

		for (int i = 0; i < Brick::getBrickCount(); i++)
		{
			if (foods[i].getMoving())
			{
				foods[i].changeYPos(foods[i].getYSpeed());
			}
		}

		ballCollidePaddle();
		ballCollideWall();
		ballCollideCeiling();
		ballCollideBrick();
		foodWithPaddle();
		powerUpFiveSeconds();
		controlBallCount();
		livesCheck();
		if (lives == 0)
			exit(0);
	}

	void drawLevel()
	{
		for (int i = 0; i < Brick::getBrickCount(); i++)
		{
			foods[i].draw();
			bricks[i].draw(brickLength, brickHeight);
		}

		for (int i = 0; i < Ball::getBallCount(); i++)
			balls[i].draw();

		//cout << Ball::getBallCount() << endl;

		paddle->draw();

		drawWall();
		drawCeiling();

	}

	void paddleFollowMouse(int x, int y)
	{
		x = x - paddle[0].getLength()/2;
		paddle->setXPos(x);
		if (x <= 30)
			paddle->setXPos(30);
		if (x >= 1020 - 30 - paddle[0].getLength())
			paddle->setXPos(1020 - 30 - paddle[0].getLength());
		//cout << paddle->getXPos() << ' ' << paddle->getYPos() << endl;
	}

	~Game()
	{
		delete[] bricks;
		delete[] balls;
		delete[] paddle;
		delete[] foods;
	}
};

#endif // GAME_H
