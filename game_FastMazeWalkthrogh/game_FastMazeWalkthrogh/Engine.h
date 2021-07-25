#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;


#include "Map.h"

class Engine
{
public:
	RenderWindow window;
	Map* map;

	Clock clock;
	float time;

	int playerX = 0;
	int playerY = 0;
	int targetX = 0;
	int targetY = 0;

	Engine();

	void init();
	void loop();
	void draw();
	void update(float time);
};

