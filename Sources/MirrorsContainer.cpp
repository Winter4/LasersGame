#include "../Headers/MirrorsContainer.h"

void MirrorsContainer::draw()
{
	for (int i = 0; i < MIRRORS_NUMBER; i++)
		mirrors[i]->draw();
}

char MirrorsContainer::checkMirrorsTargeting(sf::Vector2f laserTarget)
{
	for (int i = 0; i < MIRRORS_NUMBER; i++) {
		std::pair<bool, char> result = mirrors[i]->contains(laserTarget);
		if (result.first) {
			targetedMirror = i;
			return result.second;
		}
	}
	targetedMirror = -1;
	return 0;
}

sf::Vector2f MirrorsContainer::processLaserTargeting(sf::Vector2f laserTarget, sf::Vector2f laserVector, float laserAngle)
{
	laserAngle = mirrors[targetedMirror]->calcMirroredAngle(laserVector, laserAngle);
	laserVector = rotateSourceVector(laserAngle);

	targetedMirror = -1;
	return laserVector;
}

int MirrorsContainer::checkMouseHovering(sf::Vector2i mousePosition)
{
	for (int i = 0; i < MIRRORS_NUMBER; i++)
		if (mirrors[i]->checkMouseHovering(mousePosition))
			return i;
	return -1;
}

void MirrorsContainer::rotate(int index, int direction)
{
	assert(!(index < 0 || index > MIRRORS_NUMBER));
	mirrors[index]->rotate(direction);
}