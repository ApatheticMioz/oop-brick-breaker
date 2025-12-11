#ifndef ABSTRACT_H
#define ABSTRACT_H

#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt

using namespace std;

class Object
{
protected:
	int x_pos;
	int y_pos;

public:
	Object() : x_pos(0), y_pos(0) {}
	Object(int x_pos, int y_pos) : x_pos(x_pos), y_pos(y_pos) {}

	int getXPos() const { return x_pos; }
	int getYPos() const { return y_pos; }

	void setXPos(int x_pos)
	{
		this->x_pos = x_pos;
	}

	void setYPos(int y_pos)
	{
		this->y_pos = y_pos;
	}

	void changeXPos(int change)
	{
		this->x_pos = this->x_pos + change;
	}

	void changeYPos(int change)
	{
		this->y_pos = this->y_pos + change;
	}
};

class movingObject : public Object
{
protected:
	int x_speed;
	int y_speed;

public:
	movingObject() : Object(), x_speed(0), y_speed(0) {}
	movingObject(int x_speed, int y_speed, int x_pos, int y_pos) : Object(x_pos, y_pos), x_speed(x_speed), y_speed(y_speed) {}

	int getXSpeed() const { return x_speed; }
	int getYSpeed() const { return y_speed; }

	void setXSpeed(int x_speed)
	{
		this->x_speed = x_speed;
	}

	void setYSpeed(int y_speed)
	{
		this->y_speed = y_speed;
	}

	void changeXSpeed(int change)
	{
		this->x_speed = this->x_speed + change;
	}

	void changeYSpeed(int change)
	{
		this->y_speed = this->y_speed + change;
	}
};
#endif // ABSTRACT_H
