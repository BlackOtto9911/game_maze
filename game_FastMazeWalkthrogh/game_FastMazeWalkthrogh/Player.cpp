#include "Player.h"

Player::Player(String nameImage, Vector2f position) : Entity(nameImage, position)
{
	init();

	setPosition(position);
}

void Player::init() 
{
	width = TILE;
	height = TILE;
	rect = IntRect(0, 0, width, height);
	setTextureRect(rect);
}