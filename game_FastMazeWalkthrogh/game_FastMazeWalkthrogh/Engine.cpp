#include "Engine.h"

Engine::Engine()
{
	init();
}

void Engine::init() 
{
	window.create(VideoMode(WIDTH_MAP, HEIGHT_MAP), "Maze");
	time = 0;

	map = new Map();
	draw();
	
	cout << "Enter player's position:" << endl;
	cin >> playerX >> playerY;
	cout << "Finally, enter target's position:" << endl;
	cin >> targetX >> targetY;

	map->getCoordinates(playerX, playerY, targetX, targetY);
	map->makeWay(playerX, playerY, targetX, targetY, window);
}

void Engine::loop() 
{
	while (window.isOpen()) 
	{
		time = clock.getElapsedTime().asMicroseconds();
		time /= 800;

		clock.restart();

		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed) 
			{
				window.close();
			}
		}
		draw();
		update(time);
	}
}

void Engine::draw() 
{
	window.clear();
	map->draw(window);
	window.display();
}

void Engine::update(float time)
{
	map->update(time);
}