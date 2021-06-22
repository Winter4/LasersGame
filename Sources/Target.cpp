#include "../Headers/Target.h"

void Target::draw()
{
	TexturedEntity::draw();
}

bool Target::contains(sf::Vector2f point)
{
	return sprite.getGlobalBounds().contains(sf::Vector2f(point));
}