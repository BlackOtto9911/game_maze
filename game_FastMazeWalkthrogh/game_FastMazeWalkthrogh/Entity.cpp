#include "Entity.h"

Entity::Entity(String nameImage, Vector2f position)
{
	this->nameImage = nameImage;
	this->position = position;
	init();
}

void Entity::init()
{
	image.loadFromFile("images_game_FastMazeWalkthrogh/" + nameImage);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

void Entity::setTextureRect(IntRect rect)
{
	sprite.setTextureRect(rect);
}

void Entity::setPosition(Vector2f position)
{
	this->position = position;
	sprite.setPosition(position);
}

Vector2f Entity::getPosition()
{
	return position;
}

void Entity::setWidth(int width)
{
	this->width = width;
}
void Entity::setHeight(int height)
{
	this->height = height;
}

int Entity::getWidth()
{
	return width;
}
int Entity::getHeight()
{
	return height;
}

Sprite Entity::getSprite()
{
	return sprite;
}
