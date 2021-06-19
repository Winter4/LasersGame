#pragma once
#include "TexturedEntity.h"
#include <iostream>

class LaserGun : public TexturedEntity {
private:
	

public:
	LaserGun(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
		: TexturedEntity(window, position, texture)
	{
		sf::FloatRect rect = sprite.getLocalBounds();
		sprite.setOrigin(rect.width / 2.f,rect.height / 2.f);
		std::cout << sprite.getGlobalBounds().height << std::endl;
		sprite.setScale(0.1f, 0.1f);
		std::cout << sprite.getGlobalBounds().height << std::endl;
	}

	void draw();
	void rotate(int direction);

	sf::Vector2f getPosition();
	float getHeight();
	float getAngle();
};

