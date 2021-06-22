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
#include "MirrorsContainer.h"
#include "Button.h"
#include "Target.h"
#include "Timer.h"

class Game {
private:
	sf::RenderWindow window;
	ResourceHolder<sf::Texture, Textures::ID> texturesHolder;
	sf::Font font;

	sf::Sprite background;
	sf::Sprite field;
	LaserGun* gun;
	Laser* laser;
	WallsContainer* walls;
	MirrorsContainer* mirrors;
	Button* button;
	Target* target;
	Timer* timer;

	int activeMirror;
	bool makeMove;
	bool gameOver;

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

