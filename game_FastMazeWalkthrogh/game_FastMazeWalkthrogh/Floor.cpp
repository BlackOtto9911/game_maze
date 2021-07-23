#include "Floor.h"

Floor::Floor(String nameImage, Vector2f position) : Entity(nameImage, position)
{
	init();

	setPosition(position);
}

void Floor::init() 
{
	width = TILE;
	height = TILE;
	rect = IntRect(0, 0, width, height);
	setTextureRect(rect);
}