#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

const int TILE = 40;

class Entity
{
protected:
	Vector2f position;

	int width;
	int height;

	String nameImage;

	Image image;
	Texture texture;
	IntRect rect;
	Sprite sprite;

	void init();

public:
	Entity(String nameImage, Vector2f position);

	void setPosition(Vector2f position);
	Vector2f getPosition();

	void setWidth(int width);
	void setHeight(int height);

	int getWidth();
	int getHeight();

	void setTextureRect(IntRect rect);

	Sprite getSprite();

};

