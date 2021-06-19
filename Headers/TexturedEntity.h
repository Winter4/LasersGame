#pragma once
#include <SFML/Graphics.hpp>
#include "../Headers/Entity.h"

class TexturedEntity : public Entity {
protected:
	sf::Sprite sprite;

public:
	TexturedEntity(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
		: Entity(window)
	{
		sprite.setPosition(position);
		sprite.setTexture(texture);
	}

	void virtual draw();
};

