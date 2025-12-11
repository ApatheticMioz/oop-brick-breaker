#ifndef BRICK_H
#define BRICK_H

#include "util.h"
#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include<cmath> // for basic math functions such as cos, sin, sqrt

#include "abstract.h"

using namespace std;

class Brick : public Object
{
private:
	int color;
	int health;

	static int brickCount;

public:
	Brick() : Object(), color(-1), health(0) {}

	Brick(int color, int x_pos, int y_pos) : Object(x_pos, y_pos), color(color), health(0) {}

	int getColor() const { return color; }

	void setColor(int color)
	{
		this->color = color;
	}

	int getHealth() const { return health; }

	void setHealth()
	{
		switch(color)
		{
		case 0: // GREEN
			health = 1;
			break;
		case 1: // PINK
			health = 2;
			break;
		case 2: // BLUE
			health = 3;
			break;
		case 3: // RED
			health = 3;
			break;
		case 4: // YELLOW
			health = 2;
		}
	}

	static void setBrickCount(int brickCount)
	{
		Brick::brickCount = brickCount;
	}

	void draw(int length, int height)
	{
		if (health < 0)
			return;

		if (health == 0)
		{
			x_pos = -100;
			y_pos = -100;
		}

		switch (color)
		{
		case 0:
			DrawRectangle(x_pos, y_pos, length, height, colors[GREEN]);
			break;
		case 1:
			DrawRectangle(x_pos, y_pos, length, height, colors[PINK]);
			break;
		case 2:
			DrawRectangle(x_pos, y_pos, length, height, colors[BLUE]);
			break;
		case 3:
			DrawRectangle(x_pos, y_pos, length, height, colors[RED]);
			break;
		case 4:
			DrawRectangle(x_pos, y_pos, length, height, colors[YELLOW]);
		}
	}

	Brick operator--(int)
	{
		Brick temp(*this);
		this->health--;
		return temp;
	}

	static int getBrickCount() { return brickCount; }
};

int Brick::brickCount = 0;

#endif // BRICK_H
