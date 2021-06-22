#include "Entity.h"

class Timer : public Entity {
	private:
		sf::Text text;

		sf::Clock timer;
		short time;

	public:
		Timer(sf::RenderWindow* window, const sf::Font& font)
			: Entity(window)
		{
			text.setPosition(sf::Vector2f(435, 55));
			text.setFillColor(sf::Color::White);
			text.setFont(font);
			text.setCharacterSize(30);

			time = 60;
		}

		void substractSecond();
		sf::Time getElapsedTime();
		void restart();
		short getTime();
		void draw();
};