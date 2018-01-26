#pragma once
#include <iostream>
class Waypoint
{
private:
	float x;
	float y;
public:
	Waypoint(int sX, int sY) { x = sX, y = sY; }
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	void setX(float sX)
	{
		x= sX;
	}
	void setY(float sY)
	{
		y = sY;
	}
	bool operator==(Waypoint wP)
	{
		if (x == wP.getX() && y == wP.getY())
		{
			return true;
		}
	}
};