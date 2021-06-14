#include "Game.h"

void Game::loadAssets()
{
	texturesHolder.load(Textures::Background, "assets/textures/background.png");
	texturesHolder.load(Textures::Field, "assets/textures/field.png");
	texturesHolder.load(Textures::LaserGun, "assets/textures/gun2.png");
}

Game::Game() : window(sf::VideoMode(1200, 800), "LASERS")
{
	loadAssets();
	window.setFramerateLimit(1228);

	background.setTexture(texturesHolder.get(Textures::Background));
	field.setTexture(texturesHolder.get(Textures::Field));
	field.setPosition({ 165, 120 });

	gun = new LaserGun(&window, { 270, 230 }, texturesHolder.get(Textures::LaserGun));
}

void Game::run()
{
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	window.pollEvent(event);

	switch (event.type) {
	case sf::Event::Closed:
		window.close();
		break;

	case sf::Event::KeyPressed:
		switch (event.key.code) {
		case sf::Keyboard::Left:
			gun->rotate(-1);
			break;

		case sf::Keyboard::Right:
			gun->rotate(1);
			break;
		}
	}
}

void Game::update()
{
	system("cls");
	std::cout << sf::Mouse::getPosition(window).x << "  " << sf::Mouse::getPosition(window).y;
}

void Game::render()
{
	window.clear();

	window.draw(background);
	window.draw(field);
	gun->draw();

	window.display();
}

Game::~Game()
{
	delete gun;
}