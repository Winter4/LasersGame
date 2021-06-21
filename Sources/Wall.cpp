#include "../Headers/Wall.h"

void Wall::draw()
{
	window->draw(sprite);
}

bool Wall::contains(sf::Vector2f point) { return sprite.getGlobalBounds().contains(point); }

void Wall::setOrigin(sf::Vector2f point) { sprite.setOrigin(point); }
