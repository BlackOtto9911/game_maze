#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

const long WIDTH_MAP = 1000;
const long HEIGHT_MAP = 1000;
const int WIDTH_TILE = 25;
const int HEIGHT_TILE = 25;

#include "Entity.h"
#include "Floor.h"
#include "Wall.h"
#include "Way.h"
#include "Player.h"
#include "Target.h"

class Map
{
private:
	char** TileMap;

	list<Entity*> entities;
	Player* player;
	Target* target;

	vector<pair<int, int>> path;

	int playerX, playerY, targetX, targetY;

	void init();

public:
	Map();

	void draw(RenderWindow &window);

	void makeWay(int playerX, int playerY, int targetX, int targetY, RenderWindow& window);
	void getCoordinates(int playerX, int playerY, int targetX, int targetY);

	void update();
};

