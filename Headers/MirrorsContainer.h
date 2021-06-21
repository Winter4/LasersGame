#include <SFML/Graphics.hpp>
#include "Mirror.h"
#include <cassert>

#define MIRRORS_NUMBER 3

class MirrorsContainer {
private:
	Mirror** mirrors;
	int targetedMirror;

public:
	MirrorsContainer(sf::RenderWindow* window, const sf::Texture& texture)
	{
		targetedMirror = -1;
		mirrors = new Mirror * [MIRRORS_NUMBER];
		sf::Vector2f positions[MIRRORS_NUMBER] = { {270, 570}, {770, 570}, {770, 270} };
		
		for (int i = 0; i < MIRRORS_NUMBER; i++) 
			mirrors[i] = new Mirror(window, positions[i], texture);
	}

	void draw();
	bool checkMirrorsTargeting(sf::Vector2f laserTarget);
	sf::Vector2f processLaserTargeting(sf::Vector2f laserTarget, sf::Vector2f laserVector, float& laserAngle);
	int checkMouseHovering(sf::Vector2i mousePosition);
	void rotate(int index, int direction);
};