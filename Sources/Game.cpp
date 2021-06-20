#include "../Headers/Game.h"

void Game::loadAssets()
{
	texturesHolder.load(Textures::Background, "assets/textures/background.png");
	texturesHolder.load(Textures::Field, "assets/textures/field.png");
	texturesHolder.load(Textures::LaserGun, "assets/textures/gun2.png");
	texturesHolder.load(Textures::Mirror, "assets/textures/crystal2.png");
	texturesHolder.load(Textures::Bricks, "assets/textures/bricks.jpg");
}

Game::Game() : window(sf::VideoMode(1200, 800), "LASERS")
{
	loadAssets();
	window.setFramerateLimit(60);

	background.setTexture(texturesHolder.get(Textures::Background));
	field.setTexture(texturesHolder.get(Textures::Field));
	field.setPosition({ 165, 120 });

	gun = new LaserGun(&window, { 270, 230 }, texturesHolder.get(Textures::LaserGun));
	laser = new Laser(&window, gun->getPosition());
	walls = new WallsContainer(&window, { 500, 300 }, texturesHolder.get(Textures::Bricks));
	mirror = new Mirror(&window, { 270, 520 }, texturesHolder.get(Textures::Mirror));
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

	case sf::Event::MouseMoved:
		mirror->processMouseHovering(sf::Mouse::getPosition(window));
		break;
	}
}

void Game::update()
{
	system("cls");
	std::cout << sf::Mouse::getPosition(window).x << "  " << sf::Mouse::getPosition(window).y << std::endl;

	calcLaserTarget();
}

void Game::render()
{
	window.clear();

	window.draw(background);
	laser->draw();
	walls->draw();

	window.draw(field);
	gun->draw();
	mirror->draw();

	window.display();
}

void Game::calcLaserTarget()
{
	// повернули орт, смотрящий вверх
	// (0; -1) - смотрит вверх экрана
	// 57 - коэффициент, чтобы лазер двигался с такой же угловой скоростью, что и ствол пушки
	// подобран эмпиричски (читай: методом тыка)
	float gunAngle = gun->getAngle() / 57;
	sf::Vector2f viewDirection(0 * cosf(gunAngle) + 1 * sinf(gunAngle),
		0 * sinf(gunAngle) - 1 * cosf(gunAngle));

	// нормализовали орт (привели к единичной длине)
	viewDirection /= sqrt(viewDirection.x * viewDirection.x + viewDirection.y * viewDirection.y);
	std::cout << viewDirection.x << "  " << viewDirection.y << std::endl;

	// вектор направления лазера относительно пушки
	sf::Vector2f laserDirection(gun->getPosition() + viewDirection);
	// двигаемся в направлении взгляда пушки, пока не встретим другой объект или границу поля
	while (field.getGlobalBounds().contains(laserDirection) && !(walls->contains(laserDirection))) {
		/*
		if (mirror->processLaserTargeting(laserDirection)) {
			laser->pushVertex(laserDirection);
			break;
		}
		*/
		laserDirection += viewDirection;
	}
	// отступаем на шаг назад, чтобы лазер не вылезал с противоположного края объекта или поля
	laserDirection -= viewDirection;
	
	laser->pushVertex(laserDirection);
}

Game::~Game()
{
	delete gun;
	delete laser;
}