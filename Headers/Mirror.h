#pragma once
#include "TexturedEntity.h"
#include "Wall.h"
#include "VectorRotating.h"


class Mirror : public TexturedEntity {
private:
	sf::Vector2f mirrorVector;
	sf::Vector2f mirrorNormalVector;
	float laser_mirrorNormal_angle;

	sf::Vector2f angles[2][2];

public:
	Mirror(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
		: TexturedEntity(window, position, texture)
	{
		sprite.setScale(0.3f, 0.3f);
		sf::FloatRect size = sprite.getGlobalBounds();

		sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2,
			sprite.getLocalBounds().height / 2));

		sf::Vector2f pos = sprite.getPosition();
		angles[0][0] = sf::Vector2f(pos.x - size.width / 2, pos.y - size.height / 2);
		angles[0][1] = sf::Vector2f(pos.x + size.width / 2, pos.y - size.height / 2);
		angles[1][0] = sf::Vector2f(pos.x - size.width / 2, pos.y + size.height / 2);
		angles[1][1] = sf::Vector2f(pos.x + size.width / 2, pos.y + size.height / 2);

		rotate(360. * rand() / RAND_MAX);
	}

	void draw();
	void rotate(int direction);
	bool checkMouseHovering(sf::Vector2i mousePosition);
	float calcMirroredAngle(sf::Vector2f laserVector, float laserAngle);
	bool contains(sf::Vector2f laserTarget);

private:
	float makeLine(sf::Vector2f point, sf::Vector2f dot1, sf::Vector2f dot2);
};