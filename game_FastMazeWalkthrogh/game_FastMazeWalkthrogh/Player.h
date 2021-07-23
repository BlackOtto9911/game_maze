#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Entity.h"

class Player : public Entity
{
private:
	void init();

public:
	Vector2f speed;

	Player(String nameImage, Vector2f position);

	void setSpeed(Vector2f speed);
	Vector2f getSpeed();

	void movement();

};

