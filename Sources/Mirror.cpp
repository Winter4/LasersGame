#pragma once
#include "../Headers/Mirror.h"

void Mirror::draw()
{
	TexturedEntity::draw();

	std::cout << std::endl << "Mirror vector: " << mirrorVector.x << "  " << mirrorVector.y << std::endl;
	std::cout << "Mirror normal vector: " << mirrorNormalVector.x << "  " << mirrorNormalVector.y << std::endl;
	std::cout << "Laser - normal angle: " << laser_mirrorNormal_angle << std::endl;

	std::cout << "Angles: " << std::endl << " " << angles[0][0].x << "  " << angles[0][0].y
		<< "    " << angles[0][1].x << "  " << angles[0][1].y << std::endl
		<< " " << angles[1][0].x << "  " << angles[1][0].y << "  " << angles[1][1].x << "  " << angles[1][1].y << std::endl;
}

void Mirror::rotate(int direction)
{
	TexturedEntity::rotate(direction);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			// получить вектор относительно позиции фигуры
			sf::Vector2f pos = sprite.getPosition();
			sf::Vector2f tmp(angles[i][j] - sprite.getPosition());
			float len = sqrt(tmp.x * tmp.x + tmp.y * tmp.y);

			// повернуть вектор
			tmp = rotateVector(direction, tmp);
			angles[i][j] = sprite.getPosition() + tmp;
		}
}

bool Mirror::checkMouseHovering(sf::Vector2i mousePosition)
{
	if (contains(sf::Vector2f(mousePosition))) {
		sprite.setColor(sf::Color::Yellow);
		return true;
	}
	sprite.setColor(sf::Color::White);
	return false;
}

float Mirror::calcMirroredAngle(sf::Vector2f laserVector,  float laserAngle)
{
	// ЅерЄм вектор лазера 
	// Vector laserVector

	// ЅерЄм вектор зеркала
	mirrorVector = rotateSourceVector(sprite.getRotation());

	// »щем нормаль вектора зеркала
	mirrorNormalVector = sf::Vector2f(mirrorVector.y * (-1), mirrorVector.x);

	// »щем угол между вектором лазера и нормалью вектора зеркала
	// попутно переводим из радианов в градусы
	laser_mirrorNormal_angle = acosf(laserVector.x * mirrorNormalVector.x + laserVector.y * mirrorNormalVector.y) * 57.3;
	//laser_mirrorNormal_angle = laser_mirrorNormal_angle >= 90 ? laser_mirrorNormal_angle - 90 : laser_mirrorNormal_angle;

	// ѕрибавл€ем к углу лазера 180 +- 2 угла между нормалью
	float newAngle = laserAngle > 90 && laserAngle < 270 ?
		int(laserAngle + 180 - laser_mirrorNormal_angle * 2) % 360
		: int(laserAngle + 180 + laser_mirrorNormal_angle * 2) % 360;

	return newAngle;
}

bool Mirror::contains(sf::Vector2f laserTarget)
{
	float l1 = makeLine(laserTarget, angles[0][0], angles[0][1]);
	float l2 = makeLine(laserTarget, angles[0][1], angles[1][1]);
	float l3 = makeLine(laserTarget, angles[1][1], angles[1][0]);
	float l4 = makeLine(laserTarget, angles[1][0], angles[0][0]);

	// ѕровер€ем, внутри ли всех пр€мых
	return l1 < 0 && l2 < 0 && l3 < 0 && l4 < 0;
}

float Mirror::makeLine(sf::Vector2f point, sf::Vector2f dot1, sf::Vector2f dot2)
{
	// вывод уравнени€ пр€мой
	// (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1) ? 0
	float m1 = (point.x - dot1.x);
	float m2 = (dot2.y - dot1.y);
	float m3 = (dot2.x - dot1.x);
	float m4 = (point.y - dot1.y);

	return m1 * m2 - m3 * m4;
}