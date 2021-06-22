#pragma once
#include "TexturedEntity.h"

class Button : public TexturedEntity {
private:
	sf::Text text;

public:
	Button(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, const sf::Font& font)
		: TexturedEntity(window, position, texture)
	{
		text.setFont(font);
		text.setCharacterSize(24);
		text.setString("Make move");

		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2,
			sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2);
	}

	void draw();
	void processMouseHovering(sf::Vector2i point);
	bool processMouseClick(sf::Vector2i point);
	void end();
};