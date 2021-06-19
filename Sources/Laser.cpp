#include "../Headers/Laser.h"

void Laser::pushVertex(sf::Vertex vertex)
{
	vertexes.push_back(vertex);
}

void Laser::draw()
{
	sf::Vertex* array = &vertexes[0];
	window->draw(array, vertexes.size(), sf::Lines);

	vertexes.clear();
	vertexes.push_back(gunPosition);
}
