#pragma once
#include "Entity.h"

class LaserGun : public Entity {
private:
	

public:
	LaserGun(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
		: Entity(window, position, texture)
	{
		sf::FloatRect rect = sprite.getLocalBounds();
		sprite.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
		sprite.setScale(0.1f, 0.1f);
	}

	void draw();
	void rotate(int direction);
};

