#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Entity.h"

class Wall : public Entity
{
private:
	void init();

public:
	Wall(String nameImage, Vector2f position);
};

