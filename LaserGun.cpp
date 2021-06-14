#include "LaserGun.h"

void LaserGun::draw()
{
	Entity::draw();
}

void LaserGun::rotate(int direction)
{
	sprite.rotate(2.f * direction);

	sf::Vector2f line(1, 1);
	
}
