#include "Engine.h"

Engine::Engine()
{
	init();
}

void Engine::init() 
{
	window.create(VideoMode(WIDTH_MAP, HEIGHT_MAP), "Maze");

	map = new Map();
	draw();
	
	cout << "Enter player's position:" << endl;
	cin >> playerX >> playerY;
	cout << "Finally, enter target's position:" << endl;
	cin >> targetX >> targetY;

	map->getCoordinates(playerX, playerY, targetX, targetY);
}

void Engine::loop() 
{
	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed) 
			{
				window.close();
			}
		}
		draw();
	}
}

void Engine::draw() 
{
	window.clear();
	map->draw(window);
	window.display();
}

void Engine::update() 
{

}