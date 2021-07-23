#include "Way.h"

Way::Way(String nameImage, Vector2f position) : Entity(nameImage, position) 
{
	init();

	setPosition(position);
}

void Way::init() 
{
	width = 10;
	height = 10;
	rect = IntRect(0, 0, width, height);
	setTextureRect(rect);
}