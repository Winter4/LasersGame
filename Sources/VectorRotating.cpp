#include "../Headers/VectorRotating.h"

sf::Vector2f rotateSourceVector(float angle) {
	// ����� �� 57.3 - ��������� � ��������� ����
	return sf::Vector2f(0 * cosf(angle / 57.3) + 1 * sinf(angle / 57.3),
		0 * sinf(angle / 57.3) - 1 * cosf(angle / 57.3));
}