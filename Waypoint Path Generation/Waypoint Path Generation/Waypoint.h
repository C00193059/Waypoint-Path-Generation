#pragma once
#include <iostream>
class Waypoint
{
private:
	float x;
	float y;
public:
	float getX()
	{
		return x;
	}
	float getY()
	{
		return x;
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