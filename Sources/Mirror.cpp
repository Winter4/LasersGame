#pragma once
#include "../Headers/Mirror.h"

void Mirror::draw()
{
	TexturedEntity::draw();
	for (int i = 0; i < 2; i++)
		endfaces[i]->draw();

	std::cout << "Mirror vector: " << mirrorVector.x << "  " << mirrorVector.y << std::endl;
	std::cout << "Mirror normal vector: " << mirrorNormalVector.x << "  " << mirrorNormalVector.y << std::endl;
	std::cout << "Laser - normal angle: " << laser_mirrorNormal_angle << std::endl;
}

void Mirror::rotate(int direction)
{
	TexturedEntity::rotate(direction);
	for (int i = 0; i < ENDFACES_NUM; i++)
		endfaces[i]->rotate(direction);
}

void Mirror::processMouseHovering(sf::Vector2i point)
{
	if (sprite.getGlobalBounds().contains(sf::Vector2f(point)))
		sprite.setColor(sf::Color::Red);
	else sprite.setColor(sf::Color::White);
}

char Mirror::processLaserTargeting(sf::Vector2f point)
{
	if (sprite.getGlobalBounds().contains(point))
		return 2;
	for (int i = 0; i < ENDFACES_NUM; i++) 
		if (endfaces[i]->contains(point))
			return 1;
	return 0;
}

float Mirror::calcMirroredAngle(sf::Vector2f laserVector,  float laserAngle)
{
	// Берём вектор лазера 
	//Vector laserVector

	// Берём вектор зеркала
	mirrorVector = rotateSourceVector(sprite.getRotation());

	// Ищем нормаль вектора зеркала
	mirrorNormalVector = sf::Vector2f(mirrorVector.y * (-1), mirrorVector.x);

	// Ищем угол между вектором лазера и нормалью вектора зеркала
	// попутно переводим из радианов в градусы
	laser_mirrorNormal_angle = acosf(laserVector.x * mirrorNormalVector.x + laserVector.y * mirrorNormalVector.y) * 57.3;

	// Прибавляем к углу лазера 180 +- 2 угла между нормалью
	float newAngle = laserAngle > 90 && laserAngle < 270 ?
		int(laserAngle + 180 - laser_mirrorNormal_angle * 2) % 360
		: int(laserAngle + 180 + laser_mirrorNormal_angle * 2) % 360;

	return newAngle;
}