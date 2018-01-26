#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "Waypoint.h"
#include "SFML\Graphics.hpp"
class Path
{
private:
public:

	std::vector<Waypoint> mainPath;
	std::vector<std::vector<Waypoint>> sidePaths;
	Path() { }
	~Path() { }
	void GenerateSpline();
	float dir;
	int DoStuff(int a[5], int b[5], int c[5], int d[5]);
	void init(std::vector<Waypoint> wayPoints) { mainPath = wayPoints; }
	void addWaypoint(Waypoint waypoint) { mainPath.push_back(waypoint); }
	void createSidePath(std::vector<Waypoint> waypoints)
	{
		bool set = false;
		for (int i = 0; i < mainPath.size(); i++)
		{
			if (mainPath.at(i) == waypoints.at(0))
			{
				sidePaths.push_back(waypoints);
				set = true;
				break;
			}
		}
		if (set == false)
		{
			std::cout << "Invalid Side Path" << std::endl;
		}
	}
	// parameter t ranges from 0f to 1f
	sf::Vector2f GetBezierPosition(float t, sf::Vector2f position, float orientation, sf::Vector2f targetPos)
	{
		sf::Vector2f direction(cosf(orientation), sinf(orientation));
		sf::Vector2f p0 = position;
		sf::Vector2f p1 = p0 + direction;
		sf::Vector2f p3 = targetPos;
		sf::Vector2f p2 = p3 - direction;

		sf::Vector2f move = pow(1.0f - t, 3.0f)*p0 + 3.0f*pow(1.0f - t, 2.0f)*t*p1 + 3.0f*(1.0f - t)*pow(t, 2.0f)*p2 + pow(t, 3.0f)*p3;
		sf::Vector2f ori(move.x / (move.x + move.y), move.y / (move.x + move.y));
		dir = acosf(ori.x);
		return move;
	}
};