#pragma once
#include "TexturedEntity.h"
#include "Wall.h"
#include "VectorRotating.h"


class Mirror : public TexturedEntity {
private:
	sf::Vector2f mirrorVector;
	sf::Vector2f mirrorNormalVector;
	float laser_mirrorNormal_angle;

public:
	Mirror(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
		: TexturedEntity(window, position, texture)
	{


		sprite.setScale(0.3f, 0.3f);
		sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2,
			sprite.getLocalBounds().height / 2));

		rotate(360. * rand() / RAND_MAX);
	}

	void draw();
	void rotate(int direction);
	bool checkMouseHovering(sf::Vector2i mousePosition);
	float calcMirroredAngle(sf::Vector2f laserVector, float laserAngle);
	bool contains(sf::Vector2f laserTarget);
};