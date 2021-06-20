#include "../Headers/TexturedEntity.h"

void TexturedEntity::draw()
{
	window->draw(sprite);
}

void TexturedEntity::rotate(int direction)
{
	sprite.rotate(3.f * direction);
}
