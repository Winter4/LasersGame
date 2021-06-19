#include "../Headers/LaserGun.h"

void LaserGun::draw()
{
	TexturedEntity::draw();
}

void LaserGun::rotate(int direction)
{
	sprite.rotate(2.f * direction);
}

sf::Vector2f LaserGun::getPosition() { return sprite.getPosition(); }
float LaserGun::getHeight() { return sprite.getGlobalBounds().height; }
float LaserGun::getAngle() { return sprite.getRotation(); }