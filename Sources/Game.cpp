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
	activeMirror = -1;

	loadAssets();
	window.setFramerateLimit(60);

	background.setTexture(texturesHolder.get(Textures::Background));
	field.setTexture(texturesHolder.get(Textures::Field));
	field.setPosition({ 165, 120 });

	gun = new LaserGun(&window, { 270, 270 }, texturesHolder.get(Textures::LaserGun));
	laser = new Laser(&window, gun->getPosition());
	walls = new WallsContainer(&window, { 500, 300 }, texturesHolder.get(Textures::Bricks));
	mirrors = new MirrorsContainer(&window, texturesHolder.get(Textures::Mirror));
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

		case sf::Keyboard::A:
			if (activeMirror != -1)
				mirrors->rotate(activeMirror, -1);
			break;

		case sf::Keyboard::D:
			if (activeMirror != -1)
				mirrors->rotate(activeMirror, 1);
			break;
		}
		break;

	case sf::Event::MouseMoved:
		activeMirror = mirrors->checkMouseHovering(sf::Mouse::getPosition(window));
		break;
	}
}

void Game::update()
{
	system("cls");
	std::cout << "Mouse X Y:  " << sf::Mouse::getPosition(window).x << "  " << sf::Mouse::getPosition(window).y << std::endl << std::endl;

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
	mirrors->draw();

	window.display();
}

void Game::calcLaserTarget()
{
	// ��������� ���, ��������� �����
	// (0; -1) - ������� ����� ������
	// 57 - �����������, ����� ����� �������� � ����� �� ������� ���������, ��� � ����� �����
	// �������� ���������� (�����: ������� ����)
	// ���������� - ������ ������� �����
	float laserAngle = gun->getAngle();
	sf::Vector2f laserVector = rotateSourceVector(laserAngle);
	std::cout << "Gun angle: " << laserAngle << std::endl;

	// ������������� ��� (������� � ��������� �����)
	laserVector /= sqrt(laserVector.x * laserVector.x + laserVector.y * laserVector.y);

	std::cout << "Gun view vector:  " << laserVector.x << "  " << laserVector.y << std::endl << std::endl;

	// ����� ������ (���� ����� ���������� ��������� ������ �����������)
	sf::Vector2f laserTarget(gun->getPosition());

	enum MirrorTargeting {
		DoesNotTarget,
		TargetsEndface,
		TargetsMirror
	};

	// ���������, �� ������ �� ����� � ����� ��� ������� ����
	while (field.getGlobalBounds().contains(laserTarget) && !(walls->contains(laserTarget))) {
		// ���������, �� ������ �� � �������
		if (mirrors->checkMirrorsTargeting(laserTarget)) {
			if (laser->getVertexesNumber() > 15) break;
			else laser->pushVertex(laserTarget);

			laserTarget -= laserVector;

			laserVector = mirrors->processLaserTargeting(laserTarget, laserVector, laserAngle);
		}
		laserTarget += laserVector;
	}
	
	// ��������� �� ��� �����, ����� ����� �� ������� � ���������������� ���� ������� ��� ����
	laserTarget -= laserVector;
	std::cout << "Laser angle: " << laserAngle << std::endl;
	std::cout << "Laser target: " << laserTarget.x << "  " << laserTarget.y << std::endl;
	
	laser->pushVertex(laserTarget);
}

Game::~Game()
{
	delete gun;
	delete laser;
}