#pragma once
#include "TexturedEntity.h"

class Target : public TexturedEntity {
private:
	sf::Text text;

public:
	Target(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
		: TexturedEntity(window, position, texture)
	{
		sprite.setScale(0.05f, 0.05f);
	}

	void draw();
	bool contains(sf::Vector2f point);
};