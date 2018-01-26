
#ifndef GAME
#define GAME
#include "Path.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void update(sf::Time t_deltaTime);
	void render();
	sf::CircleShape p;
	sf::Vector2f pos;
	Path path;
	std::vector<Waypoint> wayPoints;
	int index;
	float orientation;
	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game
};

#endif // !GAME
