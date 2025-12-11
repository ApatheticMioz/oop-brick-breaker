#ifndef FOOD_H
#define FOOD_H

#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt

#include "abstract.h"

using namespace std;

class Food : public movingObject
{
private:
	int color;
	bool moving;

public:
	Food() : color(-1), moving(false)
	{
		this->x_speed = 0;
		this->y_speed = -4;
	}

	int getColor() const { return color; }

	void setTrueMoving()
	{
		moving = true;
	}

	void setFalseMoving()
	{
		moving = false;
	}

	bool getMoving() const { return moving; }

	void setColor(int color)
	{
		this->color = color;
	}

	void draw()
	{
		switch (color)
		{
		case 0:
			DrawTriangle(x_pos + 22, y_pos, x_pos + 22 + 17 + 17, y_pos, x_pos + 22 + 17, y_pos + 30, colors[GREEN]);
			break;
		case 1:
			DrawRectangle(x_pos + 25, y_pos, 30, 30, colors[PINK]);
			break;
		case 2:
			DrawCircle(x_pos + 40, y_pos + 15, 14, colors[BLUE]);
			break;
		case 3:
			DrawRectangle(x_pos + 15, y_pos, 50, 30, colors[RED]);
			break;
		case 4:
			DrawRectangle(x_pos + 25, y_pos, 30, 30, colors[YELLOW]);
		}
	}
};

#endif // FOOD_H
