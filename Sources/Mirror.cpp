#pragma once
#include "../Headers/Mirror.h"

void Mirror::draw()
{
	TexturedEntity::draw();
	for (int i = 0; i < 2; i++)
		endfaces[i]->draw();
}

void Mirror::rotate(int direction)
{
	TexturedEntity::rotate(direction);
}

void Mirror::processMouseHovering(sf::Vector2i point)
{
	if (sprite.getGlobalBounds().contains(sf::Vector2f(point)))
		sprite.setColor(sf::Color::Green);
	else sprite.setColor(sf::Color::White);
}

bool Mirror::processLaserTargeting(sf::Vector2f point)
{
	for (int i = 0; i < ENDFACES_NUM; i++)
		if (endfaces[i]->contains(point))
			return false;
}