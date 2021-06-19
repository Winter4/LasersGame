#include "../Headers/Game.h"

void Game::loadAssets()
{
	texturesHolder.load(Textures::Background, "assets/textures/background.png");
	texturesHolder.load(Textures::Field, "assets/textures/field.png");
	texturesHolder.load(Textures::LaserGun, "assets/textures/gun2.png");
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
	std::cout << sf::Mouse::getPosition(window).x << "  " << sf::Mouse::getPosition(window).y << std::endl;

	calcLaserTarget();
}

void Game::render()
{
	window.clear();

	window.draw(background);
	laser->draw();
	window.draw(field);
	gun->draw();

	window.display();
}

void Game::calcLaserTarget()
{
	// ��������� ���, ��������� �����
	// (0; -1) - ������� ����� ������
	// 57 - �����������, ����� ����� �������� � ����� �� ������� ���������, ��� � ����� �����
	// �������� ���������� (�����: ������� ����)
	float gunAngle = gun->getAngle() / 57;
	sf::Vector2f viewDirection(0 * cosf(gunAngle) + 1 * sinf(gunAngle),
		0 * sinf(gunAngle) - 1 * cosf(gunAngle));

	// ������������� ��� (������� � ��������� �����)
	viewDirection /= sqrt(viewDirection.x * viewDirection.x + viewDirection.y * viewDirection.y);
	std::cout << viewDirection.x << "  " << viewDirection.y << std::endl;

	// ������ ����������� ������ ������������ �����
	sf::Vector2f laserDirection(gun->getPosition() + viewDirection);
	// ��������� � ����������� ������� �����, ���� �� �������� ������ ������ ��� ������� ����
	while (field.getGlobalBounds().contains(laserDirection))
		laserDirection += viewDirection;
	// ��������� �� ��� �����, ����� ����� �� ������� � ���������������� ���� ������� ��� ����
	laserDirection -= viewDirection;
	
	laser->pushVertex(sf::Vertex(laserDirection));
}

Game::~Game()
{
	delete gun;
	delete laser;
}