#include "Map.h"

Map::Map()
{
	init();
}

void Map::init() 
{
	srand(time(0));

	TileMap = new char* [HEIGHT_TILE];

	for (int i = 0; i < HEIGHT_TILE; i++)
	{
		TileMap[i] = new char[WIDTH_TILE];
	}

	for (int y = 0; y < HEIGHT_TILE; y++)
	{
		for (int x = 0; x < WIDTH_TILE; x++)
		{
			if (rand() % 10 > 1) 
			{
				TileMap[y][x] = ' ';
			}
			else 
			{
				TileMap[y][x] = 'w';
			}
		}
	}

	for (int y = 0; y < HEIGHT_TILE; y++)
	{
		for (int x = 0; x < WIDTH_TILE; x++)
		{
			if (TileMap[y][x] == ' ') 
			{
				Floor* floor = new Floor("tile_map.png", Vector2f(x * TILE, y * TILE));
				entities.push_back(floor);
			}
			if (TileMap[y][x] == 'w')
			{
				Wall* wall = new Wall("tile.png", Vector2f(x * TILE, y * TILE));
				entities.push_back(wall);
			}
		}
	}

	target = new Target("target.png", Vector2f(-TILE, -TILE));
	player = new Player("player.png", Vector2f(-TILE, -TILE));

	step = 0;
	timer = 0;
}

void Map::draw(RenderWindow &window) 
{
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		window.draw((*it)->getSprite());
	}

	window.draw(target->getSprite());
	window.draw(player->getSprite());

}

void Map::makeWay(int playerX, int playerY, int targetX, int targetY, RenderWindow& window)
{
	//preparations
	//
	queue<pair<int, int>> queue;

	//
	bool** used = new bool* [HEIGHT_TILE];
	for (int i = 0; i < HEIGHT_TILE; i++)
	{
		used[i] = new bool[WIDTH_TILE];
	}

	for (int i = 0; i < HEIGHT_TILE; i++)
	{
		for (int j = 0; j < WIDTH_TILE; j++)
		{
			used[i][j] = false;
		}
	}

	//
	pair<int, int>** parent = new pair<int, int>*[HEIGHT_TILE];
	for (int i = 0; i < HEIGHT_TILE; i++)
	{
		parent[i] = new pair<int, int>[WIDTH_TILE];
	}

	//start
	//
	queue.push(pair<int, int>(playerY, playerX));
	used[playerY][playerX] = true;

	//processing
	//
	while (!queue.empty())
	{
		pair<int, int> currentPair = queue.front();
		queue.pop();

		if (currentPair.second - 1 >= 0) {
			if (used[currentPair.first][currentPair.second - 1] == false && TileMap[currentPair.first][currentPair.second - 1] != 'w')
			{
				queue.push(pair<int, int>(currentPair.first, currentPair.second - 1));
				used[currentPair.first][currentPair.second - 1] = true;

				parent[currentPair.first][currentPair.second - 1] = make_pair(currentPair.first, currentPair.second);
			}
		}
		if (currentPair.second + 1 <= WIDTH_TILE - 1) {
			if (used[currentPair.first][currentPair.second + 1] == false && TileMap[currentPair.first][currentPair.second + 1] != 'w')
			{
				queue.push(pair<int, int>(currentPair.first, currentPair.second + 1));
				used[currentPair.first][currentPair.second + 1] = true;

				parent[currentPair.first][currentPair.second + 1] = make_pair(currentPair.first, currentPair.second);
			}
		}
		if (currentPair.first - 1 >= 0) {
			if (used[currentPair.first - 1][currentPair.second] == false && TileMap[currentPair.first - 1][currentPair.second] != 'w')
			{
				queue.push(pair<int, int>(currentPair.first - 1, currentPair.second));
				used[currentPair.first - 1][currentPair.second] = true;

				parent[currentPair.first - 1][currentPair.second] = make_pair(currentPair.first, currentPair.second);
			}
		}
		if (currentPair.first + 1 <= HEIGHT_TILE - 1) {
			if (used[currentPair.first + 1][currentPair.second] == false && TileMap[currentPair.first + 1][currentPair.second] != 'w')
			{
				queue.push(pair<int, int>(currentPair.first + 1, currentPair.second));
				used[currentPair.first + 1][currentPair.second] = true;

				parent[currentPair.first + 1][currentPair.second] = make_pair(currentPair.first, currentPair.second);
			}
		}

		if (currentPair == pair<int, int>(targetY, targetX))
		{
			break;
		}
	}

	//get way back
	//
	pair<int, int> current = parent[targetY][targetX];
	path.push_back(make_pair(targetY, targetX));
	path.push_back(current);

	while (current != parent[playerY][playerX])
	{
		current = parent[current.first][current.second];
		path.push_back(current);
	}

	//end

	//draw way
	
	for (long it = path.size() - 1; it > 0; it--)
	{
		Way* way = new Way("way.png", Vector2f(path[it].second * TILE, path[it].first * TILE));
		entities.push_back(way);
	}

	Floor* floor = new Floor("tile_map.png", Vector2f(0, 0)); //fix
	entities.push_back(floor);
	

	//

	step = path.size() - 1;

	TileMap[playerY][playerX] = ' ';
	TileMap[targetY][targetX] = ' ';

	target->setPosition(Vector2f(targetX * TILE, targetY * TILE));
	player->setPosition(Vector2f(playerX * TILE, playerY * TILE));
}

void Map::getCoordinates(int playerX, int playerY, int targetX, int targetY) 
{
	this->playerX = playerX;
	this->playerY = playerY;
	this->targetX = targetX;
	this->targetY = targetY;
}

void Map::update(float time)
{
	timer += time;
	player->movement(path[step].second, path[step].first);

	if (timer > 500 && step > 0) 
	{
		step--;
		timer = 0;
	}
	if (step == 0) 
	{
		return;
	}
}