#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Entity.h"

class Floor : public Entity
{
private:
	void init();

public:
	Floor(String nameImage, Vector2f position);
};

