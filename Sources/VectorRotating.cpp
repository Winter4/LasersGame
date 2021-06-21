#include "../Headers/VectorRotating.h"

sf::Vector2f rotateSourceVector(float angle) {
	// ����� �� 57.3 - ��������� � ��������� ����
	return sf::Vector2f(0 * cosf(angle / 57.3) + 1 * sinf(angle / 57.3),
		0 * sinf(angle / 57.3) - 1 * cosf(angle / 57.3));
}

sf::Vector2f rotateVector(float angle, sf::Vector2f vector)
{
	// ����� �� 57.3 - ��������� � ��������� ����
	return sf::Vector2f(vector.x * cosf(angle / 57.3) - vector.y * sinf(angle / 57.3),
		vector.x * sinf(angle / 57.3) + vector.y * cosf(angle / 57.3));
}