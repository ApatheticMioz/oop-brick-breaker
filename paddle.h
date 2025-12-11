#ifndef PADDLE_H
#define PADDLE_H

#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt

#include "abstract.h"

using namespace std;

class Paddle : public Object
{
private:
	int length;
	int height;
	int color;

public:
	Paddle() : Object()
	{
		this->length = 160;
		this->height = 30;
		this->x_pos = 430;
		this->y_pos = 10;
		color = 0;
	}

	int getLength() const {	return length; }
	int getHeight() const { return height; }
	int getColor() const { return color; }

	void setLength(int length)
	{
		this->length = length;
	}

	void setColor(int color)
	{
		this->color = color;
	}

	void draw()
	{
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

};

#endif // PADDLE_H
