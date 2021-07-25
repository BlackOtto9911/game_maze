#include "Way.h"

Way::Way(String nameImage, Vector2f position) : Entity(nameImage, position) 
{
	init();

	setPosition(position);
}

void Way::init() 
{
	width = 40;
	height = 40;
	rect = IntRect(0, 0, width, height);
	setTextureRect(rect);
}