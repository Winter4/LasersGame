#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "ResourceHolder.hpp"
#include "Enums.h"
#include "LaserGun.h"

class Game {
private:
	sf::RenderWindow window;
	ResourceHolder<sf::Texture, Textures::ID> texturesHolder;

	sf::Sprite background;
	sf::Sprite field;
	LaserGun* gun;

public:
	Game();
	~Game();
	void run();

private:
	void loadAssets();

	void processEvents();
	void update();
	void render();
};

