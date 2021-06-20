#pragma once
#include "TexturedEntity.h"
#include "Wall.h"

// 2 - кол-во торцов у зеркала
#define ENDFACES_NUM 2

class Mirror : public TexturedEntity {
private:
	Wall** endfaces; // невидимые стены по торцам зеркала

public:
	Mirror(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
		: TexturedEntity(window, position, texture)
	{
		//sprite.setScale(0.15f, 0.3f);
		sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2,
			sprite.getGlobalBounds().height / 2));

		endfaces = new Wall * [2];
		for (int i = 0; i < ENDFACES_NUM; i++) {
			endfaces[i] = new Wall(window, sprite.getPosition(), sf::Vector2f(sprite.getGlobalBounds().width, 1.f));
			endfaces[i]->setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2,
				sprite.getGlobalBounds().height / 2 - sprite.getGlobalBounds().height * i));
		}
	}

	void draw();
	void rotate(int direction);
	void processMouseHovering(sf::Vector2i point);
	bool processLaserTargeting(sf::Vector2f point);
};