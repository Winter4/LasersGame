#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "VectorRotating.h"

#include "ResourceHolder.hpp"
#include "Enums.h"
#include "LaserGun.h"
#include "Laser.h"
#include "WallsContainer.h"
#include "Mirror.h"

class Game {
private:
	sf::RenderWindow window;
	ResourceHolder<sf::Texture, Textures::ID> texturesHolder;

	sf::Sprite background;
	sf::Sprite field;
	LaserGun* gun;
	Laser* laser;
	WallsContainer* walls;
	Mirror* mirror, *mirror2;

public:
	Game();
	~Game();
	void run();

private:
	void loadAssets();

	void processEvents();
	void update();
	void render();

	void calcLaserTarget();
};

