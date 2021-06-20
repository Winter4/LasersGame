#pragma once
#include "Entity.h"

class Wall : public Entity {
private:
	sf::RectangleShape sprite;

public:
	Wall(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, const sf::Texture* texture)
		: Entity(window)
	{
		sprite.setPosition(position);
		sprite.setSize(size);
		//sprite.setTexture(texture, true);

		sprite.setFillColor(sf::Color::Red);
	}

	void draw();
	bool contains(sf::Vector2f point);
};