#pragma once
#include <iostream>
#include <vector>
#include "Waypoint.h"
class Path
{
private:
	std::vector<Waypoint> mainPath;
	std::vector<std::vector<Waypoint>> sidePaths;
public:
	Path(std::vector<Waypoint> wayPoints) { mainPath = wayPoints; }
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
};