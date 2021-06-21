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
		sprite.setScale(0.3f, 0.3f);
		sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2,
			sprite.getLocalBounds().height / 2));

		endfaces = new Wall * [2];
		for (int i = 0; i < ENDFACES_NUM; i++) {
			endfaces[i] = new Wall(window, sprite.getPosition(), sf::Vector2f(sprite.getGlobalBounds().width, 2.f));
			endfaces[i]->setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2,
				sprite.getGlobalBounds().height / 2 - sprite.getGlobalBounds().height * i));
		}

		rotate(360. * rand() / RAND_MAX);
	}

	void draw();
	void rotate(int direction);
	bool checkMouseHovering(sf::Vector2i mousePosition);
	float calcMirroredAngle(sf::Vector2f laserVector, float laserAngle);
	std::pair<bool, char> contains(sf::Vector2f laserTarget);
	void rotate(int index, int direction);
};