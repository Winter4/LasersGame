#include "../Headers/TexturedEntity.h"

void TexturedEntity::draw()
{
	window->draw(sprite);
}

void TexturedEntity::rotate(int direction)
{
	sprite.rotate(1.f * direction);
}
