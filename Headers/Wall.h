#pragma once
#include "Entity.h"
#include <iostream>

class Wall : public Entity {
private:
	sf::RectangleShape sprite;

public:
	Wall(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size)
		: Entity(window)
	{
		sprite.setPosition(position);
		sprite.setSize(size);
	}

	Wall(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, const sf::Texture& texture)
		: Wall(window, position, size)
	{
		sprite.setTexture(&texture, true);
	}

	void draw();
	bool contains(sf::Vector2f point);
	void setOrigin(sf::Vector2f point);
};