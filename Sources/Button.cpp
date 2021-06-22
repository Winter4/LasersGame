#include "../Headers/Button.h"

void Button::draw()
{
	TexturedEntity::draw();
	window->draw(text);
}

void Button::processMouseHovering(sf::Vector2i point)
{
	if (sprite.getGlobalBounds().contains(sf::Vector2f(point))) sprite.setColor(sf::Color::Yellow);
	else sprite.setColor(sf::Color::White);
}

bool Button::processMouseClick(sf::Vector2i point)
{
	return sprite.getGlobalBounds().contains(sf::Vector2f(point));
}

void Button::end()
{
	text.setString("Game over\nClose the window");
	text.move(-30, -15);
}