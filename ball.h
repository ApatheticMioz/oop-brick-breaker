#ifndef BALL_H
#define BALL_H

#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt

#include "abstract.h"

using namespace std;

class Ball : public movingObject
{
private:
	int color;
	int radius;

	int timeCreation;
	int timePowerup;

	int lastPowerup;

	static int magnitude;
	static int ballCount;

public:
	Ball() : color(1), timeCreation(time(0)), timePowerup(0), lastPowerup(-1)
	{
		this->x_speed = 0;
		this->y_speed = -10;
		this->x_pos = 505;
		this->y_pos = 300;
		this->radius = 10;
	}

	Ball(const Ball& ball)
	{
		this->x_speed = ball.x_speed;
		this->y_speed = ball.y_speed;
		this->x_pos = GetRandInRange(40, 800);
		this->y_pos = GetRandInRange(30, 400);
		x_pos = (x_pos / 10) * 10;
		y_pos = (y_pos / 10) * 10;
		this->color = ball.color;
		this->timeCreation = ball.timeCreation;
		this->timePowerup = ball.timePowerup;
		this->radius = ball.radius;
		this->lastPowerup = ball.lastPowerup;
	}

	Ball& operator= (const Ball& ball)
	{
		if (this != &ball)
		{
			this->x_speed = ball.x_speed;
			this->y_speed = ball.y_speed;
			this->x_pos = GetRandInRange(40, 800);
			this->y_pos = GetRandInRange(30, 400);
			x_pos = (x_pos / 10) * 10;
			y_pos = (y_pos / 10) * 10;
			this->color = ball.color;
			this->timeCreation = ball.timeCreation;
			this->timePowerup = ball.timePowerup;
			this->radius = ball.radius;
			this->lastPowerup = ball.lastPowerup;
		}

		return *this;
	}

	void setLast(int l)
	{
		lastPowerup = l;
	}

	int getLast() const { return lastPowerup; }

	void startPowerupTimer()
	{
		timePowerup = time(0);
	}

	int returnCreationTimeElapsed()
	{
		return time(0) - timeCreation;
	}

	int returnPowerupTimeElapsed()
	{
		return time(0) - timePowerup;
	}

	void setPowerupTimeElapsed(int s)
	{
		timePowerup = s;
	}

	int getRadius() const { return radius; }

	void draw()
	{
		switch (color)
		{
		case 0:
			DrawCircle(x_pos, y_pos, radius, colors[GREEN]);
			break;
		case 1:
			DrawCircle(x_pos, y_pos, radius,  colors[PINK]);
			break;
		case 2:
			DrawCircle(x_pos, y_pos, radius, colors[BLUE]);
			break;
		case 3:
			DrawCircle(x_pos, y_pos, radius, colors[RED]);
			break;
		case 4:
			DrawCircle(x_pos, y_pos, radius, colors[YELLOW]);
		}
	}

	int getColor() const { return color; }

	void setColor(int color)
	{
		this->color = color;
	}

	static int getBallCount()
	{
		return Ball::ballCount;
	}

	void updatePosition()
	{
		this->changeXPos(x_speed);
		this->changeYPos(y_speed);
	}

	static void setMagnitude(int mag)
	{
		Ball::magnitude = mag;
	}

	static int getMag() { return Ball::magnitude; }

	Ball operator++(int)
	{
		Ball temp(*this);
		Ball::ballCount++;
		return temp;
	}

	Ball operator--(int)
	{
		Ball temp(*this);
		Ball::ballCount--;
		return temp;
	}
};

int Ball::ballCount = 0;
int Ball::magnitude = 10;

#endif // BALL_H
