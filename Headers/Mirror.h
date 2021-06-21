#pragma once
#include "TexturedEntity.h"
#include "Wall.h"
#include "VectorRotating.h"

// 2 - кол-во торцов у зеркала
#define ENDFACES_NUM 2

class Mirror : public TexturedEntity {
private:
	Wall** endfaces; // невидимые стены по торцам зеркала
	sf::Vector2f mirrorVector = { 0, -1 };
	sf::Vector2f mirrorNormalVector;
	float laser_mirrorNormal_angle;

public:
	Mirror(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
		: TexturedEntity(window, position, texture)
	{
		sprite.setScale(1.f, 4.f);
		sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2,
			sprite.getLocalBounds().height / 2));

		endfaces = new Wall * [2];
		for (int i = 0; i < ENDFACES_NUM; i++) {
			endfaces[i] = new Wall(window, sprite.getPosition(), sf::Vector2f(sprite.getGlobalBounds().width, 2.f));
			endfaces[i]->setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2,
				sprite.getGlobalBounds().height / 2 - sprite.getGlobalBounds().height * i));
		}
	}

	void draw();
	void rotate(int direction);
	void processMouseHovering(sf::Vector2i point);
	char processLaserTargeting(sf::Vector2f point);
	float calcMirroredAngle(sf::Vector2f laserVector, float laserAngle);
};