#include "Game.h"

Game::Game():
	m_window{ sf::VideoMode{ 1408, 1280, 32 }, "SFML Game" },
		//m_window(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Boids", sf::Style::None),

		m_exitGame{ false } //when true game will exit
{
	index = 0;
	Waypoint w1(1, 1);
	wayPoints.push_back(w1);
	Waypoint w2(200, 400);
	wayPoints.push_back(w2);
	Waypoint w3(800, 550);
	wayPoints.push_back(w3);
	Waypoint w4(1000, 750);
	wayPoints.push_back(w4);
	path.init(wayPoints);
	p.setRadius(5);
	pos = sf::Vector2f(path.mainPath.at(index).getX(), path.mainPath.at(index).getY());
}
Game::~Game()
{
}
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
void Game::update(sf::Time timePerFrame) //60 fps
{
	//dont do every update
	orientation = path.dir;
	if (index < 3)
	{
		pos  = (path.GetBezierPosition(0.05f, pos, orientation, (sf::Vector2f(path.mainPath.at(index + 1).getX(), path.mainPath.at(index + 1).getY()))));
	}
	else if (index == 3)
	{
		pos = path.GetBezierPosition(0.05f, pos, orientation, (sf::Vector2f(path.mainPath.at(index - 1).getX(), path.mainPath.at(index - 1).getY())));
	}
	if (pos.x >= path.mainPath.at(1).getX() && pos.y >= path.mainPath.at(1).getY())
	{
		index = 1;
	}
	if (pos.x >= path.mainPath.at(2).getX() && pos.y >= path.mainPath.at(2).getY())
	{
		index = 2;
	}
	if (pos.x >= path.mainPath.at(3).getX() && pos.y >= path.mainPath.at(3).getY())
	{
		index = 3;
	}
	p.setPosition(pos);
}
void Game::render()
{
	m_window.clear();
	m_window.draw(p);
	m_window.display();
}