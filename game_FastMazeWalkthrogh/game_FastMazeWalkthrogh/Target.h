#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Entity.h"

class Target : public Entity
{
private:
	void init();

public:
	Target(String nameImage, Vector2f position);
};

