#pragma once
#include "../Headers/Mirror.h"

void Mirror::draw()
{
	TexturedEntity::draw();

	std::cout << std::endl << "Mirror vector: " << mirrorVector.x << "  " << mirrorVector.y << std::endl;
	std::cout << "Mirror normal vector: " << mirrorNormalVector.x << "  " << mirrorNormalVector.y << std::endl;
	std::cout << "Laser - normal angle: " << laser_mirrorNormal_angle << std::endl;
}

void Mirror::rotate(int direction)
{
	TexturedEntity::rotate(direction);
}

bool Mirror::checkMouseHovering(sf::Vector2i mousePosition)
{
	if (sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
		sprite.setColor(sf::Color::Yellow);
		return true;
	}
	sprite.setColor(sf::Color::White);
	return false;
}

float Mirror::calcMirroredAngle(sf::Vector2f laserVector,  float laserAngle)
{
	// Берём вектор лазера 
	// Vector laserVector

	// Берём вектор зеркала
	mirrorVector = rotateSourceVector(sprite.getRotation());

	// Ищем нормаль вектора зеркала
	mirrorNormalVector = sf::Vector2f(mirrorVector.y * (-1), mirrorVector.x);

	// Ищем угол между вектором лазера и нормалью вектора зеркала
	// попутно переводим из радианов в градусы
	laser_mirrorNormal_angle = acosf(laserVector.x * mirrorNormalVector.x + laserVector.y * mirrorNormalVector.y) * 57.3;
	//laser_mirrorNormal_angle = laser_mirrorNormal_angle >= 90 ? laser_mirrorNormal_angle - 90 : laser_mirrorNormal_angle;

	// Прибавляем к углу лазера 180 +- 2 угла между нормалью
	float newAngle = laserAngle > 90 && laserAngle < 270 ?
		int(laserAngle + 180 - laser_mirrorNormal_angle * 2) % 360
		: int(laserAngle + 180 + laser_mirrorNormal_angle * 2) % 360;

	return newAngle;
}

bool Mirror::contains(sf::Vector2f laserTarget)
{
	if (sprite.getGlobalBounds().contains(laserTarget))
		return true;
	return false;
}