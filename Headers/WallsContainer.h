#pragma once
#include "Wall.h"

#define BASE_WALLS_NUMBER 3

class WallsContainer {
private:
	Wall** walls;

public:
	WallsContainer(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& textures)
	{
		walls = new Wall * [3];
		walls[0] = new Wall(window, position, { 200, 20 }, textures);
		walls[1] = new Wall(window, position + sf::Vector2f(0, 200), { 200, 20 }, textures);
		walls[2] = new Wall(window, position, { 20, 200 }, textures);
	}

	void draw();
	bool contains(sf::Vector2f point);
};