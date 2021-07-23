#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Entity.h"

class Way : public Entity
{
private:
	void init();

public:
	Way(String nameImage, Vector2f position);
};

