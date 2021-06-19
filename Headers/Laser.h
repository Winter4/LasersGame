#pragma once
#include "Entity.h"
#include <vector>

class Laser : public Entity {
private:
	std::vector<sf::Vertex> vertexes;
	sf::Vertex gunPosition;

public:
	Laser(sf::RenderWindow* window, sf::Vector2f gunPosition)
		: Entity(window)
	{
		this->gunPosition = sf::Vertex(gunPosition);
		vertexes.push_back(gunPosition);
	}

	void pushVertex(sf::Vertex vertex);
	void draw();
};

