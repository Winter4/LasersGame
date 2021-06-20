#pragma once
#include "../Headers/WallsContainer.h"

void WallsContainer::draw()
{
	for (int i = 0; i < BASE_WALLS_NUMBER; i++)
		walls[i]->draw();
}

bool WallsContainer::contains(sf::Vector2f point)
{
	for (int i = 0; i < BASE_WALLS_NUMBER; i++)
		if (walls[i]->contains(point))
			return true;
	return false;
}